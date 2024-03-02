#include "HotDrinks.h"
#include "HotDrinkFactory.h"


int main()
{
    HotDrinksFactory factory;
    std::unique_ptr<IHotDrinks> tea = factory.create_drink("tea");
    tea->prepare();

    return 0;
}
