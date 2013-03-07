#include "simulation.hpp"
#include "profile/profile.hpp"
#include <kalman/kalman1d.hpp>

Simulation::Simulation(): m_realAccelerationX(1), m_basicSpeedX(1), m_basicPositionX(1), m_gpsPositionX(1), m_kalmanAccelerationX(1), m_kalmanBiasX(1), m_kalmanSpeedX(1), m_kalmanPositionX(1)
{}

const Signal& Simulation::realAccelerationX() const
{
    return m_realAccelerationX;
}

const Signal& Simulation::basicSpeedX() const
{
    return m_basicSpeedX;
}

const Signal& Simulation::basicPositionX() const
{
    return m_basicPositionX;
}

const Signal& Simulation::gpsPositionX() const
{
    return m_gpsPositionX;
}

void Simulation::run(boost::weak_ptr<Profile> profile_wk)
{
    boost::shared_ptr<Profile> profile = profile_wk.lock();
    if(!profile) return;

    size_t N = profile->N();
    m_realAccelerationX = profile->accelerationX() + Signal::noise(profile->te(), N, 0.2, 0.1);
    m_basicSpeedX = m_realAccelerationX.integrate();
    m_basicPositionX = m_basicSpeedX.integrate();

    size_t gpsn = profile->gpsN();
    size_t ratio = N / gpsn;
    m_gpsPositionX = Signal(profile->gpsTe(), gpsn);
    for(size_t i = 0; i < gpsn; i++)
        m_gpsPositionX[i] = profile->positionX()[i*ratio];
    if(profile->noisyGPS())
    {
        m_gpsPositionX += Signal::noise(profile->gpsTe(), gpsn, 0, 100);
    }

    //run Kalman filter
    m_kalmanAccelerationX = Signal(profile->te(), N);
    m_kalmanBiasX = Signal(profile->te(), N);
    m_kalmanSpeedX = Signal(profile->te(), N);
    m_kalmanPositionX = Signal(profile->te(), N);

    Kalman1D kf;
    size_t j = 0;
    for(size_t i = 0; i < N; i++)
    {
        Matrix<1, 1> input(m_realAccelerationX[i]);

        kf.predict(input);

        if(i % ratio == 0)
        {
            Matrix<1, 1> measurement = m_gpsPositionX[j];
            kf.update(measurement);
            j++;
        }

        const Matrix<4,1>& state = kf.state();
        m_kalmanAccelerationX[i] = state(0, 0);
        m_kalmanBiasX[i] = state(1, 0);
        m_kalmanSpeedX[i] = state(2, 0);
        m_kalmanPositionX[i] = state(3, 0);
    }
}
