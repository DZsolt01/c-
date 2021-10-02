#include "Point.h"

using namespace std;

int main(int argc, char** argv) {

    srand(time(NULL));
    
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    pp1->print();
    cout << distance(*pp1,*pp2) <<endl;
    pp1->testIsSquare("points.txt");
    Point* arrayOfPoints = pp1->createArray(10);
    arrayOfPoints->printArray(arrayOfPoints, 10);
    pair<Point, Point> pointof = closestPoints(arrayOfPoints, 10);
    cout << pointof.first.getX() << " " << pointof.first.getY() << " " << pointof.second.getX() << " " << pointof.second.getY() << " " << distance(pointof.first, pointof.second)<<endl;
    pointof = farthestPoints(arrayOfPoints, 10);
    cout << pointof.first.getX() << " " << pointof.first.getY() << " " << pointof.second.getX() << " " << pointof.second.getY() << " " << distance(pointof.first, pointof.second);
    delete[] arrayOfPoints;
    delete pp1;
    delete pp2;
    return 0;
}