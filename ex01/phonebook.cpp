#include <stdio.h>
#include "./phonebook.hpp"
#include <string.h>

void PhoneBook::add_contact(Contact contact)
{
    if (contact_number == 8)
    {
        std::cout << "The phonebook is full, if you wish to enter a new contact, the last one will be erased."
        "Please, enter the name of the contact: " << std::endl;

        std::cin >> contact.name;
        std::cout << "Please, enter the phone number for " << contact.name << std::endl;
        std::cin >> contact.phone_number;

        contact[7] = contact;
    }

    std::cout << "Please, enter the name of the contact: " << contact.name << std::endl;
}
int main()
{
    PhoneBook phonebook;
    Contact contact;

    char buffer[6];
    std::cout << "Please, enter <ADD>, <SEARCH> or <EXIT>" << std::endl;
    std::cin >> buffer;

    if (!(strcmp(buffer, "ADD")) || !(strcmp(buffer, "SEARCH") || !(strcmp(buffer, "EXIT"))))
    {
        std::cout << "Wrong input" << std::endl;
        return (0);
    }
    if (strcmp(buffer, "ADD"))
    {
        std::cout << "Please, enter the name of the contact: " << std::endl;
        std::cin >> contact.name;




    }
    return (0);
}