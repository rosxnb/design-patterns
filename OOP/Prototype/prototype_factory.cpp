#include <memory>
#include "prototype.hpp"

class EmployeeFactory
{
    public:
        static std::unique_ptr<Contact> new_employee_same_office(const std::string& name, const int suite)
        {
            return EmployeeFactory::from_prototype(EmployeeFactory::contact_ref, name, suite);
        }

    private:
        static const Contact contact_ref;
        static std::unique_ptr<Contact> from_prototype(const Contact& prototype, const std::string& name, const int suite)
        {
            auto p = std::make_unique<Contact>(prototype);
            p->name = name;
            p->address->suite = suite;
            return p;
        }
};

const Contact EmployeeFactory::contact_ref = Contact{ "", new Address{ "123East Dr", "London", 0 } };


int main()
{
    std::unique_ptr<Contact> david = EmployeeFactory::new_employee_same_office("David", 101);
    std::unique_ptr<Contact> molly = EmployeeFactory::new_employee_same_office("Molly", 901);

    std::cout << *david << std::endl;
    std::cout << *molly << std::endl;

    return 0;
}
