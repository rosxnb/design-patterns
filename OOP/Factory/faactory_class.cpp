#include <iostream>
#include <cmath>

class Point
{
    public:
        friend std::ostream& operator<< (std::ostream& os, const Point& p)
        {
            os << "Point{ x=" << p.x << ", y=" << p.y << " }";
            return os;
        }

    private:
        float x, y;

        Point(float x, float y)
            : x{x}, y{y}
        {}

        struct PointFactory
        {
            Point NewPolar(float r, float theta) const
            {
                float x = r * cosf(theta);
                float y = r * sinf(theta);
                return {x, y};
            }

            Point NewCartesian(float x, float y) const
            {
                return {x, y};
            }

        };

    public:
        static constexpr PointFactory Factory = PointFactory();
};

int main()
{
    Point p = Point::Factory.NewCartesian(5, 19);
    Point p1 = Point::Factory.NewPolar(5, M_PI_2);

    std::cout << p << std::endl;
    std::cout << p1 << std::endl;
}
