#include "PhoneBook.hpp"

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