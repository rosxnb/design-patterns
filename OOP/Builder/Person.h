#pragma once
#include <string>
#include <iostream>

class PersonBuilder;

class Person
{
    public:
        ~Person()
        {
            std::cout << "~Person() \n";
        }

        static PersonBuilder create();

        Person(Person&& other)
            : street_address{std::move(other.street_address)},
            post_code{std::move(other.post_code)},
            city{std::move(other.city)},
            company_name{std::move(other.company_name)},
            position{std::move(other.position)},
            annual_income{other.annual_income}
        {
        }

        Person& operator=(Person&& other)
        {
            if (this == &other)
                return *this;
            street_address = std::move(other.street_address);
            post_code = std::move(other.post_code);
            city = std::move(other.city);
            company_name = std::move(other.company_name);
            position = std::move(other.position);
            annual_income = other.annual_income;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Person& obj)
        {
            return os
                << "street_address: " << obj.street_address
                << " post_code: " << obj.post_code
                << " city: " << obj.city
                << " company_name: " << obj.company_name
                << " position: " << obj.position
                << " annual_income: " << obj.annual_income;
        }

        friend class PersonBuilder;
        friend class PersonAddressBuilder;
        friend class PersonJobBuilder;

    private:
        // address
        std::string street_address, post_code, city;

        // employment
        std::string company_name, position;
        int annual_income = 0;

        Person()
        {
            std::cout << "Person() \n";
        }
};
