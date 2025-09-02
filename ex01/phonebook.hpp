#include <iostream>

class Contact
{
    public:
    std::string name;
    int phone_number;
};

class PhoneBook
{
    public:
    void add_contact(Contact contact);
    
    private:
    Contact contact[8];
    int contact_number = 0;
};
