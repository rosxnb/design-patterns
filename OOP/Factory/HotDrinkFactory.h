#pragma once
#include <functional>
#include <unordered_map>
#include "HotDrinks.h"

class IHotDrinkFactory
{
    public:
        virtual ~IHotDrinkFactory() = default;
        virtual std::unique_ptr<IHotDrinks> create_drink() const = 0;
};

class TeaFactory : public IHotDrinkFactory
{
    public:
        std::unique_ptr<IHotDrinks> create_drink() const override
        {
            return std::make_unique<Tea>();
        }
};

class CoffeeFactory : public IHotDrinkFactory
{
    public:
        std::unique_ptr<IHotDrinks> create_drink() const override
        {
            return std::make_unique<Coffee>();
        }
};

class HotDrinksFactory
{
    public:
        HotDrinksFactory()
        {
            drink_objects["tea"] = [] { return std::make_unique<Tea>(); };
            drink_objects["coffee"] = [] { return std::make_unique<Coffee>(); };
        }

        std::unique_ptr<IHotDrinks> create_drink(const std::string& name)
        {
            return drink_objects[name]();
        }

    private:
        std::unordered_map< std::string, std::function< std::unique_ptr<IHotDrinks>(void) > > drink_objects;
};
