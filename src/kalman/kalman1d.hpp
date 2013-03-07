#ifndef KALMAN1D_HPP
#define KALMAN1D_HPP

#include "kalmanfilter.hpp"

class Kalman1D : public KalmanFilter<4, 1, 1>
{
public:
    Kalman1D();
};

#endif // KALMAN1D_HPP
