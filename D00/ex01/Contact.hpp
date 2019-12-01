#ifndef CPP_CONTACT_HPP
#define CPP_CONTACT_HPP



class Contact
{
private:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email;
    std::string date;
    std::string phone;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;
    int Is_phone_bad(std::string);
    int Is_mail_bad(std::string);
    int Is_date_bad(std::string);

public:
    void SetContact(int);
    void GetContact();
    int  Is_hollow();
    void ListContacts();
    int convert_to_int(std::string);
};

#endif //CPP_CONTACT_H
