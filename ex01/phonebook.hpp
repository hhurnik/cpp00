#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int contact_number;
        Contact contacts[8];
        int oldest_contact;
        
    public:
        PhoneBook();
        void add_contact();
        void search();

        int get_contact_number() const { return contact_number; }
    
};

#endif


