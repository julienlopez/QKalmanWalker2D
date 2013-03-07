#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <utils/signal.hpp>

#include <string>
/**
  * \brief contains the basic movement of a simulation.
  *
  * Mostly acceleration, speed and position along the two axis.
  */
class Profile
{
public:
    Profile(const std::string& id, std::size_t size, double Te, double gpsTe);

    const std::string& id() const;
    double te() const;
    double gpsTe() const;
    std::size_t N() const;
    std::size_t gpsN() const;

    Signal& sampleTime();
    const Signal& sampleTime() const;

    Signal& gpsSampleTime();
    const Signal& gpsSampleTime() const;

    Signal& accelerationX();
    const Signal& accelerationX() const;
    Signal& accelerationY();
    const Signal& accelerationY() const;

    Signal& speedX();
    const Signal& speedX() const;
    Signal& speedY();
    const Signal& speedY() const;

    Signal& positionX();
    const Signal& positionX() const;
    Signal& positionY();
    const Signal& positionY() const;

    bool noisyGPS() const;
    void setNoisyGPS(bool b);

private:
    double m_te;
    double m_gpste;
    std::string m_id;
    Signal m_time;
    Signal m_gpstime;
    Signal m_acceleration_x;
    Signal m_acceleration_y;
    Signal m_speed_x;
    Signal m_speed_y;
    Signal m_position_x;
    Signal m_position_y;

    bool m_noisyGPS;
};

#endif // PROFILE_HPP
