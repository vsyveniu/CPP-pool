#include <iostream>
#include <regex>
#include <sstream>
#include "Contact.hpp"

int   Contact::Is_phone_bad(std::string phone)
{
    if(phone == "")
        return 0;
    std::regex pattern("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{2}-[[:digit:]]{2}");

    if(std::regex_match(phone, pattern))
    {
        return 0;
    }
    return 1;
}
int   Contact::Is_mail_bad(std::string mail)
{
    if(mail == "")
        return 0;
    std::regex pattern("(\\w+)@(\\w+)\\.(\\w+)");

    if(std::regex_match(mail, pattern))
    {
        return 0;
    }
    return 1;
}
int   Contact::Is_date_bad(std::string date)
{
    if(date == "")
        return 0;
    std::string delimiter = ".";
    std::string subnum;
    std::regex pattern("[[:digit:]]{2}\\.[[:digit:]]{2}\\.[[:digit:]]{4}");
    if(std::regex_match(date, pattern))
    {

            for (int i = 0; i < 3; i++)
            {
                subnum = date.substr(0, date.find(delimiter));
                date.erase(0, date.find(delimiter) + delimiter.length());
                if(i == 0 && convert_to_int(subnum) > 31) {
                    return 1;
                }
                if(i == 1 && convert_to_int(subnum) > 12) {
                    return 1;
                }
                if(i == 2 && convert_to_int(subnum) > 2019)
                    return 1;

            }
            return 0;
    }
    return 1;
}

int Contact::convert_to_int(std::string str)
{
    int num;
    std::istringstream iss (str);
    iss >> num;
    return num;
}

void  Contact::SetContact(int i)
{
    index = i;
    std::cout << "Enter first name: ";
    getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    getline(std::cin, last_name);
    std::cout << "Enter  nickname: ";
    getline(std::cin, nickname);
    std::cout << "Enter login: ";
    getline(std::cin, login);
    std::cout << "Enter postal address: ";
    getline(std::cin, postal_address);
    std::cout << "Enter email in format example@mail.com: ";
    getline(std::cin, email);
    while(Is_mail_bad(email))
    {
        std::cout << "Try another one" << std::endl;
        getline(std::cin, email);
    }

    std::cout << "Enter phone number in format like nnn-nnn-nn-nn: ";
    getline(std::cin, phone);
    while(Is_phone_bad(phone))
    {
        std::cout << "Try another one" << std::endl;
        getline(std::cin, phone);
    }
    std::cout << "Enter birthday date in format like dd.mm.yyyy : ";
    getline(std::cin, date);
    while(Is_date_bad(date))
    {
        std::cout << "Try another one" << std::endl;
        getline(std::cin, date);
    }

    std::cout << "Enter favorite meal: ";
    getline(std::cin, favorite_meal);
    std::cout << "Enter darkest secret: ";
    getline(std::cin, darkest_secret);
}
void Contact::GetContact()
{

    std::cout << "first name: " + first_name<< std::endl;
    std::cout << "last name: " + last_name << std::endl;
    std::cout << "nickname: " + nickname << std::endl;
    std::cout << "login: " + login << std::endl;
    std::cout << "postal address: " + postal_address << std::endl;
    std::cout << "email: " + email << std::endl;
    std::cout << "phone number: " + phone << std::endl;
    std::cout << "date: " + date << std::endl;
    std::cout << "favorite meal: " + favorite_meal << std::endl;
    std::cout << "darkest secret: " + darkest_secret << std::endl;
}

std::string cut_to_10_wide(std::string str)
{
    int len = str.length();

    if(len > 10){
        str.resize(10);
        str[9] = '.';
    }
    if(len < 10)
    {
        str.resize(10);
        for(int i = len; i < 10; i++)
        {
            str[i] = ' ';
        }
    }
    return str;
}

int  Contact::Is_hollow()
{
    int error = 1;
    (first_name != "") ? error = 0 : 0;
    (last_name != "") ? error = 0 : 0;
    (nickname != "") ? error = 0 : 0;
    (login != "") ? error = 0 : 0;

    return (error);
}

void Contact::ListContacts()
{
    std::cout << "|";std::cout << index; std::cout << "         |";
    (first_name != "") ? std::cout << cut_to_10_wide(first_name) + "|" : std::cout << cut_to_10_wide("empty") + "|";
    (last_name != "") ? std::cout <<  cut_to_10_wide(last_name) + "|" : std::cout << cut_to_10_wide("empty") + "|";
    (nickname != "") ? std::cout << cut_to_10_wide(nickname) + "|" : std::cout << cut_to_10_wide("empty") + "|";
    std::cout << std::endl;
}