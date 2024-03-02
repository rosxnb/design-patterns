#include "prototype.hpp"

int main()
{
    Contact john{ "John", new Address{ "123East Dr", "London", 123 } };
    Contact jane{ john };
    jane.name = "Jane";
    jane.address->suite = 103;

    std::cout << john << std::endl;
    std::cout << jane << std::endl;
}
