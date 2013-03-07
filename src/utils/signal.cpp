#include "signal.hpp"

#include <utils/binary_functions/math.hpp>

#include <cstdlib>
#include <numeric>

Signal::Signal(double Te, std::size_t N): std::vector<double>(N), m_te(Te)
{}

Signal::Signal(double Te, std::size_t N, double value): std::vector<double>(N, value), m_te(Te)
{}

double Signal::mean() const
{
    return std::accumulate(begin(), end(), 0., Mean());
}

double Signal::variance() const
{
    return variance(mean());
}

Signal& Signal::operator +=(double d)
{
    for(iterator i = begin(); i != end(); ++i)
        *i += d;
    return *this;
}

Signal& Signal::operator -=(double d)
{
    return (*this) += -d;
}

Signal& Signal::operator *=(double d)
{
    for(iterator i = begin(); i != end(); ++i)
        *i *= d;
    return *this;
}

Signal& Signal::operator /=(double d)
{
    return (*this) *= 1/d;
}

Signal Signal::operator+(const Signal& s) const
{
    Signal res(m_te, size());
    for(size_t i = 0; i < size(); i++)
        res[i] = at(i) + s.at(i);
    return res;
}

Signal& Signal::operator+=(const Signal& s)
{
    for(size_t i = 0; i < size(); i++)
        (*this)[i] += s.at(i);
    return *this;
}

Signal Signal::noise(double Te, std::size_t N, double mean, double variance)
{
    Signal res(Te, N);
    for(std::size_t i = 0; i < N; i++)
        res[i] = rand();

    double currentMean = res.mean();
    res -= currentMean;

    double sigma = res.variance();

    res *= sqrt(variance/sigma);
    res += mean;

    return res;
}

Signal Signal::derive() const
{
    size_t N = size();
    Signal res(m_te, N);
    for(size_t i = 1; i < N; i++)
        res[i] = (at(i) - at(i-1)) / m_te;
    return res;
}

Signal Signal::integrate(double start) const
{
    size_t N = size();
    Signal res(m_te, N);
    if(N > 0) res[0] = start;
    for(size_t i = 1; i < N; i++)
        res[i] = m_te * at(i) + res[i-1];
    return res;
}

double Signal::variance(double mean) const
{
    return std::accumulate(begin(), end(), 0., Variance(mean)) / size();
}
