#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

class Line {
public:
    Point point1, point2;

    Line(Point p1, Point p2) : point1(p1), point2(p2) {}

    double length() {
        double dx = point2.x - point1.x;
        double dy = point2.y - point1.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(3, 4);

    Line line1(p1, p2);

    cout << "Length of line: " << line1.length() << endl;

    return 0;
}