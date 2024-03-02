// compile command:
//      clang++ -std=c++17 facets.cpp Person.cpp PersonBuilder.cpp


#include <iostream>
#include <string>
#include <string>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main()
{
    Person p = Person::create()
        .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
        .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

    std::cout << p << std::endl;
    return 0;
}
