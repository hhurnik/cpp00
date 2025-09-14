#include <stdio.h>
#include "./phonebook.hpp"
#include <string.h>

void Contact::fill_contact()
{
    std::cout << "First name: " << std::endl;
    std::getline(std::cin, first_name);
    std::cout << "Last name: " << std::endl;
    std::getline(std::cin, last_name);
    std::cout << "Nickname: " << std::endl;
    std::getline(std::cin, nickname);
    std::cout << "Tell me your darkest secret: " << std::endl;
    std::getline(std::cin, darkest_secret);
    std::cout << "Phone number: " << std::endl;
    std::getline(std::cin, phone_number);
}

//takes a contact object and inserts it into the array
void PhoneBook::add_contact()
{
    Contact c;
    c.fill_contact();
    
    if (contact_number == 8)
    {
        //replace the oldest one
        //it will be circular- first the first one, 
        //then the second, ... , the last one and back to 0th
        contacts[oldest_one] = c;
        if (oldest_one == 7)
            oldest_one = 0;
        else
            oldest_one++; //the next oldest
    }
    else
    {
        contacts[contact_number] = c;
        oldest_one = 0;
        contact_number++;
    }
}
//right aligned, max 10 chars
std::string format_field(std::string field)
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    else
        return (std::string(10 - field.length(), ' ') + field);
}

/* Display  the saved contacts as a list of 4 columns
 - each column 10 characters wide, "|" seperates them, right aligned */
void PhoneBook::search()
{
    Contact c;
    std::cout << "     Index | First name |  Last name |   Nickname" << std::endl;
    std::cout << "       ";
    std::cout << contact_number;
    std::cout << " | ";
    std::cout << c.first_name;




}

PhoneBook::PhoneBook()
{
    contact_number = 0;
}

int main()
{
    PhoneBook phonebook;
    Contact contact;
    std::string command;

    while (command != "EXIT")
    {
        std::cout << "Please, enter <ADD>, <SEARCH> or <EXIT>" << std::endl;
        std::getline(std::cin, command);

        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search();


            
    }
    return (0);
}