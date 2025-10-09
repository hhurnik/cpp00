#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string darkest_secret;
        std::string phone_number;
    public:
        void fill_contact();

        std::string get_first_name() const { return first_name; }
        std::string get_last_name() const { return last_name; }
        std::string get_nickname() const { return nickname; }
        std::string get_darkest_secret() const { return darkest_secret; }
        std::string get_phone_number() const { return phone_number; }

};

#endif


