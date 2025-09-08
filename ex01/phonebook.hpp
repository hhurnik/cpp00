#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string.h>

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
};

//a saved contact cant have empty fields

class PhoneBook
{
    private:
        Contact contacts[8];
        int contact_number;
        
    public:
        PhoneBook();
        void add_contact();
    
};

#endif


