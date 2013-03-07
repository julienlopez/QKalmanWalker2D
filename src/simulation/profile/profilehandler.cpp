#include "profilehandler.hpp"
#include "profile.hpp"

#include <cmath>

ProfileHandler::ProfileHandler()
{}

void ProfileHandler::loadProfiles()
{
    //TODO setup loading from file, for now, just create a basic test profile
    double Te = 1./100;
    int N = 6000;
    boost::shared_ptr<Profile> p(new Profile("simple test profile", N, Te, 1));
    instance().add(p);
    double A = 9.81/4;
    int i = 0;

    for(; i < 1000; i++) {
        p->accelerationX()[i] = 0;
        p->accelerationY()[i] = 0;
        p->speedX()[i] = 0;
        p->speedY()[i] = 0;
        p->positionX()[i] = 0;
        p->positionY()[i] = 0;
    }

    for(; i < 2000; i++) {
        p->accelerationX()[i] = A;
        p->accelerationY()[i] = 0;
        p->speedX()[i] = A*Te*(i-1000);
        p->speedY()[i] = 0;
        p->positionX()[i] = A*pow(Te*(i-1000), 2)/2;
        p->positionY()[i] = 0;
    }

    double pos = p->positionX()[i-1];
    double speed = p->speedX()[i-1];
    for(; i < 4000; i++) {
        p->accelerationX()[i] = 0;
        p->accelerationY()[i] = 0;
        p->speedX()[i] = p->speedX()[i-1];
        p->speedY()[i] = 0;
        p->positionX()[i] = pos + speed * Te * (i-2000);
        p->positionY()[i] = 0;
    }

    pos = p->positionX()[i-1];
    speed = p->speedX()[i-1];
    for(; i < 5000; i++) {
        p->accelerationX()[i] = -A;
        p->accelerationY()[i] = 0;
        p->speedX()[i] = speed - A*Te*(i-4000);
        p->speedY()[i] = 0;
        p->positionX()[i] = pos + speed * Te * (i-4000) - A*pow(Te*(i-4000), 2)/2;
        p->positionY()[i] = 0;
    }

    pos = p->positionX()[i-1];
    for(; i < N; i++) {
        p->accelerationX()[i] = 0;
        p->accelerationY()[i] = 0;
        p->speedX()[i] = p->speedX()[i-1];
        p->speedY()[i] = 0;
        p->positionX()[i] = pos;
        p->positionY()[i] = 0;
    }

    instance().m_current = p;
}

ProfileHandler::profile_sp ProfileHandler::current()
{
    return instance().m_current;
}

bool ProfileHandler::setCurrent(const std::string& id)
{
    type_map::iterator i = instance().m_profiles.find(id);
    if(i == instance().m_profiles.end()) return false;
    instance().m_current = i->second;
    return true;
}

ProfileHandler::type_map::const_iterator ProfileHandler::begin()
{
    return instance().m_profiles.begin();
}

ProfileHandler::type_map::const_iterator ProfileHandler::end()
{
    return instance().m_profiles.end();
}

void ProfileHandler::add(const profile_sp& profile)
{
    m_profiles.insert(make_pair(profile->id(), profile));
}
