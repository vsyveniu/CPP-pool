#include <iostream>
#include <sstream>
#include <string>
#include "Contact.hpp"



int Is_bad(int num, int i)
{
    if(num >= 1 && num <= i)
        return 0;
    else
        return 1;
}

int main()
{
    std::string str;
    Contact     contact[8];
    int i = 0;
    int j = 0;
    int index;
    std::string index_input;

    std::cout << "Welcome to the best phonebook ever. Usage: ADD, SEARCH, EXIT " << std::endl;
    while(str != "EXIT")
    {
        getline(std::cin, str);
        if(str == "ADD" && i == 8)
        {
            std::cout << "no more records" << std::endl;
        }
        else if( str == "ADD" && i <= 8)
        {
            std::cout << "Enter all the fields as program says: " << std::endl;
            contact[i].SetContact(i + 1);
            i++;
            std::cout << "Next command: " << std::endl;
        }
        else if(str == "SEARCH" && i == 0)
        {
            std::cout << "There is empty" << std::endl;
        }
        else if(str == "SEARCH")
        {
                for (j = 0; j < i; j++) {
                    if (!contact[j].Is_hollow()) {
                        contact[j].ListContacts();
                    }
                }
                std::cout << "Enter the index" << std::endl;
                getline(std::cin, index_input);
                index = contact->convert_to_int(index_input);
                while(Is_bad(index, i))
                {
                    if(index_input == "EXIT") {
                        std::cout << "Exit phonebook" << std::endl;
                        return 0;
                    }
                    std::cout << "Try another one" << std::endl;
                    getline(std::cin, index_input);
                    index = contact->convert_to_int(index_input);
                }
                contact[index - 1].GetContact();
                std::cout << "Next command: " << std::endl;

        }
        else if(str != "EXIT")
            {
                std::cout << "You wrote a crap" << std::endl;
                std::cout << "Usage: ADD, SEARCH, EXIT" << std::endl;
            }
    }
    std::cout << "Exit phonebook" << std::endl;
    return 0;
}