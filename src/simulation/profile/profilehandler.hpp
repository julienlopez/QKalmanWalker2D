#ifndef PROFILEHANDLER_HPP
#define PROFILEHANDLER_HPP

#include <utils/singleton.hpp>

#include <map>

#include <boost/shared_ptr.hpp>

class Profile;

class ProfileHandler : public Singleton<ProfileHandler>
{
    friend class Singleton<ProfileHandler>;
public:
    typedef boost::shared_ptr<Profile> profile_sp;
    typedef boost::shared_ptr<Profile> profile_wp;
    typedef std::map<std::string, profile_sp> type_map;

    static void loadProfiles();

    static profile_sp current();

    static bool setCurrent(const std::string& id);

    static type_map::const_iterator begin();
    static type_map::const_iterator end();

private:
    type_map m_profiles;
    profile_sp m_current;

    ProfileHandler();

    void add(const profile_sp& profile);


};

#endif // PROFILEHANDLER_HPP
