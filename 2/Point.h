#include <utility>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <ctime>

using namespace std;
#ifndef POINT_H
    #define POINT_H
    class Point{

    private: int x, y;
    public: Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
    
    bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
    void testIsSquare(const char * filename);
    Point* createArray(int numPoints);
    void printArray(Point* points, int numPoints);
    
    };
double distance(const Point& a, const Point& b);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);
pair<Point, Point> closestPointsOptimized(Point* points, int numPoints);
#endif /* PONT_H */
