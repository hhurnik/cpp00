#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int contact_number;
        
    public:
        PhoneBook();
        Contact contacts[8];
        void add_contact();
        int oldest_one;
        void search();

        int get_contact_number() const { return contact_number; }
    
};

#endif


