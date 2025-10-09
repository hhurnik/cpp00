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
}