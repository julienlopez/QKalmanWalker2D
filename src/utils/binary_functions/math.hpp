#ifndef MATH_HPP
#define MATH_HPP

#include <functional>
#include <cmath>

class Mean : public std::binary_function<double, double, double>
{
public:
    Mean()
    {
        n = 0;
    }

    double operator()(double x, double y)
    {
        n++;
        return (x*(n-1)+y)/n;
    }

private:
    std::size_t n;
};

class Variance : public std::binary_function<double, double, double>
{
public:
    Variance(double mean): m_mean(mean)
    {}

    double operator()(double x, double y)
    {
        return x + pow(y - m_mean, 2);
    }

private:
    double m_mean;
};

#endif // MATH_HPP
