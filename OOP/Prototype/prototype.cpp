#include "prototype.hpp"

Address::Address() = default;

Address::Address(const std::string& street, const std::string& city, int suite)
    : street{street}, city{city}, suite{suite}
{}

std::ostream& operator<< (std::ostream& os, const Address& obj)
{
    os << "Street: " << obj.street << ", City: " << obj.city << ", Suite: " << obj.suite;
    return os;
}


Contact::Contact(const std::string name, Address* address)
    : name{name}, address{address}
{}

Contact::Contact(const Contact& other)
    : name{other.name}
{
    address = new Address();
    address->street = other.address->street;
    address->city = other.address->city;
    address->suite = other.address->suite;
}

std::ostream& operator<< (std::ostream& os, const Contact& obj)
{
    os << "Name: " << obj.name << ", " << *(obj.address);
    return os;
}

Contact::~Contact() { delete address; }
