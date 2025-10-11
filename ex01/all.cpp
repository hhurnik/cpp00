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


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string>
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


#include "Contact.hpp"

void Contact::fill_contact()
{
    //first Name
    while (first_name.empty())
    {
        std::cout << "First name: ";
        std::getline(std::cin, first_name);
        if (first_name.empty())
            std::cout << "First name cannot be empty. Please enter it again." << std::endl;
    }

    //last Name
    while (last_name.empty())
    {
        std::cout << "Last name: ";
        std::getline(std::cin, last_name);
        if (last_name.empty())
            std::cout << "Last name cannot be empty. Please enter it again." << std::endl;
    }

    //nickname
    while (nickname.empty())
    {
        std::cout << "Nickname: ";
        std::getline(std::cin, nickname);
        if (nickname.empty())
            std::cout << "Nickname cannot be empty. Please enter it again." << std::endl;
    }

    //phone Number
    while (phone_number.empty())
    {
        std::cout << "Phone number: ";
        std::getline(std::cin, phone_number);
        if (phone_number.empty())
            std::cout << "Phone number cannot be empty. Please enter it again." << std::endl;
    }

    //darkest Secret
    while (darkest_secret.empty())
    {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, darkest_secret);
        if (darkest_secret.empty())
            std::cout << "Darkest secret cannot be empty. Please enter it again." << std::endl;
    }
}#include "PhoneBook.hpp"
#include "Contact.hpp"

//moje
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
        contacts[oldest_contact] = c;
        if (oldest_contact == 7)
            oldest_contact = 0;
        else
            oldest_contact++; //the next oldest
    }
    else
    {
        contacts[contact_number] = c;
        //oldest_contact = 0;
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
    int i;
    std::string input;
    int index;
    Contact c;

    int number_contact = 0;
    i = 0;

    if (get_contact_number() == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::cout << format_field("Index") << " | " << format_field("First name") << " | " << format_field("Last name") << " | " << format_field("Nickname") << std::endl;

    while (i < get_contact_number())
    {


        std::cout << "         " << number_contact;
        std::cout << " | ";
        std::cout << format_field(contacts[i].get_first_name());
        std::cout << " | ";
        std::cout << format_field(contacts[i].get_last_name());
        std::cout << " | ";
        std::cout << format_field(contacts[i].get_nickname()) << std::endl;

        number_contact++;
        i++;
    }
    /*Then, prompt the user again for the index of the entry to display. If the index
    is out of range or wrong, define a relevant behavior. Otherwise, display the
    contact information, one field per line*/
    std::cout << "Which index would you like to display?: " << std::endl;
    std::getline(std::cin, input);

    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    //convert to int
    index = input[0] - '0';

    if (index < 0 || index >= get_contact_number())
    {
        std::cout << "Index smaller than 0 or exceeds the last existing contact" << std::endl;
        return;
    }

    std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;

}

PhoneBook::PhoneBook()
{
    contact_number = 0;
    oldest_contact = 0;
}

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    //Contact contact;
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