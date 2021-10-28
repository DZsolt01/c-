#include "Point.h"
int Point::counter{0};
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
    counter++;
}
double Point::distanceTo(const Point& point) const {
    double dx = point.getX() - x;
    double dy = point.getY() - y;
    return sqrt(dx*dx + dy*dy);
}
int Point::getX() const {
    return x;
}
int Point::getY() const{
    return y;
}

Point::Point(const Point &copy) {
    this->x = copy.getX();
    this->y = copy.getY();
    counter++;
}

Point::~Point() {
    counter--;
}

int Point::getCounter() {
    return counter;
}
