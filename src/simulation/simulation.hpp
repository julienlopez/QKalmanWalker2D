#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <utils/singleton.hpp>
#include <utils/signal.hpp>

#include <boost/weak_ptr.hpp>

class Profile;

class Simulation : public Singleton<Simulation>
{
    friend class Singleton<Simulation>;

    Simulation();

public:
    const Signal& realAccelerationX() const;
    const Signal& basicSpeedX() const;
    const Signal& basicPositionX() const;
    const Signal& gpsPositionX() const;

    void run(boost::weak_ptr<Profile> profile_wk);

private:
    Signal m_realAccelerationX;
    Signal m_basicSpeedX;
    Signal m_basicPositionX;
    Signal m_gpsPositionX;
    Signal m_kalmanAccelerationX;
    Signal m_kalmanBiasX;
    Signal m_kalmanSpeedX;
    Signal m_kalmanPositionX;
};

#endif // SIMULATION_HPP
