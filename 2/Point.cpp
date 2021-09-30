// Point.cpp - implementáció
#include <iostream>
#include <sstream>
#include "Point.h"
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "x:" << getX() << " y:" << getY() <<endl;;
}

double Point::distance(const Point& a, const Point& b){
    double dis = 0;
    double dx = b.getX() - a.getX();
    double dy = b.getY() - a.getY();

    dis = sqrt(dx*dx + dy*dy);

    return dis;
}

bool Point::isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    double distances[6];

    distances[0] = distance(a,b);
    distances[1] = distance(a,c);
    distances[2] = distance(a,d);
    distances[3] = distance(b,c);
    distances[4] = distance(c,d);
    distances[5] = distance(b,d);

    sort(distances, distances+6);
    if(distances[0] <= 0){
        return false;
    }
    if(distances[0] != distances[3]){
        return false;
    }
    if(distances[4] != distances[5]){
        return false;
    }
    if(distances[3] == distances[4]){
        return false;
    }
    return true;
}

void Point::testIsSquare(const char * filename){
    try
    {
        string line;
        ifstream ifs(filename);

        if(!ifs){
            cout << "Error" << endl;
            return;
        }

        while(getline(ifs, line) ){
            istringstream iss(line);
            int x,y;
            iss >> x >> y;
            Point p1(x,y);
            iss >> x >> y;
            Point p2(x,y);
            iss >> x >> y;
            Point p3(x,y);
            iss >> x >> y;
            Point p4(x,y);
            if(isSquare(p1,p2,p3,p4)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}