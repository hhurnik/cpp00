#include "PhoneBook.hpp"
#include "Contact.hpp"

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
    int i;
    std::string input;
    int index;
    Contact c;

    int number_contact = 0;
    i = 0;

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
    oldest_one = 0;
}

