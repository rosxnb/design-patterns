#include <iostream>

class Address
{
    public:
        Address();
        Address(const std::string& street, const std::string& city, int suite);
        friend std::ostream& operator<< (std::ostream& os, const Address& obj);

    public:
        std::string street;
        std::string city;
        int suite;
};

class Contact
{
    public:
        std::string name;
        Address* address;

        Contact(const std::string name, Address* address);
        Contact(const Contact& other);
        friend std::ostream& operator<< (std::ostream& os, const Contact& obj);
        ~Contact();
};
