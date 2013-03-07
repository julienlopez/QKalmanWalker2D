#include "profile.hpp"

#include <cmath>

Profile::Profile(const std::string &id, std::size_t size, double Te, double gpsTe): m_te(Te), m_gpste(gpsTe), m_id(id), m_time(Te, size), m_gpstime(gpsTe, (size_t)floor(size*Te/gpsTe)),
    m_acceleration_x(Te, size), m_acceleration_y(Te, size), m_speed_x(Te, size), m_speed_y(Te, size), m_position_x(Te, size), m_position_y(Te, size), m_noisyGPS(false)
{
    for(size_t i = 0; i < size; i++)
        m_time[i] = i*Te;

    size_t gpsn = gpsN();
    for(size_t i = 0; i < gpsn; i++)
        m_gpstime[i] = i*gpsTe;
}

const std::string& Profile::id() const
{
    return m_id;
}

double Profile::te() const
{
    return m_te;
}

double Profile::gpsTe() const
{
    return m_gpste;
}

std::size_t Profile::N() const
{
    return m_time.size();
}

std::size_t Profile::gpsN() const
{
    return m_gpstime.size();
}

Signal& Profile::sampleTime()
{
    return m_time;
}

const Signal& Profile::sampleTime() const
{
    return m_time;
}

Signal& Profile::gpsSampleTime()
{
    return m_gpstime;
}

const Signal& Profile::gpsSampleTime() const
{
    return m_gpstime;
}

Signal& Profile::accelerationX()
{
    return m_acceleration_x;
}

const Signal& Profile::accelerationX() const
{
    return m_acceleration_x;
}

Signal& Profile::accelerationY()
{
    return m_acceleration_y;
}

const Signal& Profile::accelerationY() const
{
    return m_acceleration_y;
}

Signal& Profile::speedX()
{
    return m_speed_x;
}

const Signal& Profile::speedX() const
{
    return m_speed_x;
}

Signal& Profile::speedY()
{
    return m_speed_y;
}

const Signal& Profile::speedY() const
{
    return m_speed_y;
}

Signal& Profile::positionX()
{
    return m_position_x;
}

const Signal& Profile::positionX() const
{
    return m_position_x;
}

Signal& Profile::positionY()
{
    return m_position_y;
}

const Signal& Profile::positionY() const
{
    return m_position_y;
}

bool Profile::noisyGPS() const
{
    return m_noisyGPS;
}

void Profile::setNoisyGPS(bool b)
{
    m_noisyGPS = b;
}
