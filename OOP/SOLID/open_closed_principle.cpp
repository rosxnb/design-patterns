#include <iostream>
#include <string>
#include <vector>

enum class Color { RED, GREEN, BLUE };
enum class Size { SMALL, MEDIUM, LARGE };

std::ostream& operator<< (std::ostream& os, const Color& color)
{
    std::string s;
    switch(color)
    {
        case Color::RED:
            s = "RED";
            break;
        case Color::GREEN:
            s = "GREEN";
            break;
        case Color::BLUE:
            s = "BLUE";
            break;
        default:
            s = "No Color";
    }
    os << s;
    return os;
}

std::ostream& operator<< (std::ostream& os, const Size& size)
{
    std::string s;
    switch(size)
    {
        case Size::SMALL:
            s = "SMALL";
            break;
        case Size::MEDIUM:
            s = "MEDIUM";
            break;
        case Size::LARGE:
            s = "LARGE";
            break;
        default:
            s = "No Size";
    }
    os << s;
    return os;
}

struct Product
{
    std::string name;
    Size size;
    Color color;

    friend std::ostream& operator<< (std::ostream& print, const Product* const p);
};

std::ostream& operator<< (std::ostream& os, const Product* const p)
{
    os << "Name: " << p->name << ", Color: " << p->color << ", Size: " << p->size;
    return os;
}

struct NaiveProductFilter
{
    using Items = std::vector<Product*>;

    Items filter_by_color(const Items& items, const Color& color)
    {
        Items result;
        for (auto& item: items)
        {
            if (item->color == color)
            {
                result.push_back(item);
            }
        }

        return result;
    }

    Items filter_by_size(const Items& items, const Size& size)
    {
        Items result;
        for (auto& item: items)
        {
            if (item->size == size)
            {
                result.push_back(item);
            }
        }

        return result;
    }

    Items filter_by_color_and_size(const Items& items, const Color& color, const Size& size)
    {
        Items result;
        for (auto& item: items)
        {
            if (item->color == color && item->size == size)
            {
                result.push_back(item);
            }
        }

        return result;
    }
};


template <typename T>
struct Specification
{
    virtual ~Specification() = default;
    virtual bool is_satisfied(const T* const item) const = 0;
};

template <typename T>
struct Filter
{
    virtual std::vector<T*> filter(const std::vector<T*>& items, const Specification<T>& spec) const = 0;
};

struct ProductFilter : Filter<Product>
{
    std::vector<Product*> filter(const std::vector<Product*>& items, const Specification<Product>& spec) const override
    {
        std::vector<Product*> result;
        for (Product* p: items)
        {
            if (spec.is_satisfied(p))
            {
                result.push_back(p);
            }
        }

        return result;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(Size size)
        : size{size}
    {}

    bool is_satisfied(const Product* const item) const override
    {
        return item->size == size;
    }
};

struct ColorSpecification: Specification<Product>
{
    Color color;

    explicit ColorSpecification(Color color)
        : color{color}
    {}

    bool is_satisfied(const Product* const item) const override
    {
        return item->color == color;
    }
};

struct AndSpecification: Specification<Product>
{
    SizeSpecification size;
    ColorSpecification color;

    explicit AndSpecification(SizeSpecification size, ColorSpecification color)
        : size{size}, color{color}
    {}

    bool is_satisfied(const Product* const item) const override
    {
        return size.is_satisfied(item) && color.is_satisfied(item);
    }
};

AndSpecification operator&& (const SizeSpecification& size, const ColorSpecification& color)
{
    return AndSpecification(size, color);
}


int main(int argc, const char** argv)
{
    Product apple{"Apple", Size::SMALL, Color::GREEN};
    Product tree{"Tree", Size::LARGE, Color::GREEN};
    Product house{"House", Size::LARGE, Color::BLUE};

    const std::vector<Product*> products { &apple, &tree, &house };

    // This method is not scaleable
    // Becuase it requires changing the already implemented class
    std::cout << "Products with BLUE color: \n";
    auto blue_products = NaiveProductFilter().filter_by_color(products, Color::BLUE);
    std::copy(blue_products.begin(), blue_products.end(), std::ostream_iterator<Product*>(std::cout, "\n"));


    ProductFilter pf;
    SizeSpecification slarge(Size::LARGE);
    ColorSpecification cgreen(Color::GREEN);

    std::cout << "\nProducts with GREEN color: \n";
    auto green_products = pf.filter(products, cgreen);
    std::copy(green_products.begin(), green_products.end(), std::ostream_iterator<Product*>(std::cout, "\n"));

    std::cout << "\nProducts with LARGE size and GREEN color: \n";
    // AndSpecification spec = slarge && cgreen;
    AndSpecification spec = SizeSpecification{Size::LARGE} && ColorSpecification{Color::GREEN};
    auto filtered_products = pf.filter(products, spec);
    std::copy(filtered_products.begin(), filtered_products.end(), std::ostream_iterator<Product*>(std::cout, "\n"));

    return 0;
}
