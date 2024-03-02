#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
    public:
        operator Person() const
        {
            return std::move(person);
        }

        // builder facets
        PersonAddressBuilder lives() const;
        PersonJobBuilder works() const;

    protected:
        Person& person;
        explicit PersonBuilderBase(Person& person)
            : person{ person }
        {
        }

};

class PersonBuilder : public PersonBuilderBase
{
    public:
        PersonBuilder(): PersonBuilderBase{p}
        {
        }

    private:
        Person p;
};
