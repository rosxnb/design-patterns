#pragma once
#include <iostream>

class IHotDrinks
{
    public:
        virtual ~IHotDrinks() = default;
        virtual void prepare() = 0;
};

class Tea : public IHotDrinks
{
    public:
        void prepare() override
        {
            std::cout << "Tea : HotDrink" << std::endl;
        }
};

class Coffee : public IHotDrinks
{
    public:
        void prepare() override
        {
            std::cout << "Coffee : HotDrink" << std::endl;
        }
};
