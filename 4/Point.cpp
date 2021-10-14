#include "Point.h"

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
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
