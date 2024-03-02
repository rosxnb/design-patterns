#include <iostream>
#include <cmath>

class Point
{
    public:
        static Point NewPolar(float r, float theta)
        {
            float x = r * cosf(theta);
            float y = r * sinf(theta);
            return {x, y};
        }

        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        }

        friend std::ostream& operator<< (std::ostream& os, const Point& p)
        {
            os << "{ x = " << p.x << ", y= " << p.y << "}";
            return os;
        }

    private:
        float x, y;

        Point(float x, float y)
            : x{x}, y{y}
        {}
};
