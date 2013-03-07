#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <vector>

class Signal : public std::vector<double>
{
public:
    Signal(double Te, std::size_t N = 0);
    Signal(double Te, std::size_t N, double value);

    //utility functions
    double mean() const;
    double variance() const;

    //arithmetic operators
    Signal& operator +=(double d);
    Signal& operator -=(double d);
    Signal& operator *=(double d);
    Signal& operator /=(double d);

    Signal operator+(const Signal& s) const;
    Signal& operator+=(const Signal& s);

    static Signal noise(double Te, std::size_t N, double mean, double variance);

    Signal derive() const;
    Signal integrate(double start = 0) const;

private:
    double m_te;
    double variance(double mean) const;
};

#endif // SIGNAL_HPP
