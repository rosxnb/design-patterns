#include <iostream>

/*
   Demonstrates the violation of Liskov-Substitution Principle.
   Refer to README.md of this folder for further explanation.
*/

class Rectangle
{
    protected:
        int height, width;

    public:
        Rectangle(int height, int width)
            : height{height}, width{width}
        {}

        int get_height() { return height; }
        int get_width() { return width; }
        int get_area() { return width * height; }

        virtual void set_height(int height) { this->height = height; }
        virtual void set_width(int width) { this->width = width; }
};

class Square : public Rectangle
{
    Square(int size)
        : Rectangle(size, size)
    {}

    void set_height(int height) override { this->height = height; }
    void set_width(int width) override { this->width = width; }
};

void process(Rectangle& shape)
{
    int width = shape.get_width();
    int height = 10;
    shape.set_height(height);

    std::cout << "Expected area:   " << width * height << std::endl;
    std::cout << "Calculated area: " << shape.get_area() << std::endl;
}
