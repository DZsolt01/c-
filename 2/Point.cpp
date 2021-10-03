// Point.cpp - implementáció
#include "Point.h"

double random_num(int min, int max){
    return rand() % (max - min) + min;
}



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

double distance(const Point& a, const Point& b){
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
Point* Point::createArray(int numPoints) {
    Point *points = new Point[numPoints];

    if(!points){
        cout << "ERROR" << endl;
        return nullptr;
    }
    for(int i = 0; i < numPoints; ++i){
        points[i] = Point(random_num(0,2000), random_num(0,2000));
    }
    return points;
}
void Point::printArray(Point* points, int numPoints){
    for(int i =0 ; i < numPoints; ++i){
        cout << "Point x:"<<points[i].getX() << " y:" << points[i].getY() << endl;
    }
}

pair<Point, Point> closestPoints(Point* points, int numPoints){
    pair<Point, Point> max;
    max.first = points[0];
    max.second = points[1];
    for(int i = 0; i < numPoints-1; ++i){
        for(int j = i+1; j < numPoints; ++j){
            if(distance(max.first, max.second) > distance(points[i], points[j])){
                max.first = points[i];
                max.second = points[j];
            }
        }
    }
    return max;
}
pair<Point, Point> farthestPoints(Point* points, int numPoints){
    pair<Point, Point> max;
    max.first = points[0];
    max.second = points[1];
    for(int i = 0; i < numPoints-1; ++i){
        for(int j = i+1; j < numPoints; ++j){
            if(distance(max.first, max.second) < distance(points[i], points[j])){
                max.first = points[i];
                max.second = points[j];
            }
        }
    }
    return max;
}

bool comparex(Point const & p1, Point const& p2){
    if(p1.getX() > p2.getX()){
        return 1;
    }
    if(p1.getX() < p2.getX()){
        return 0;
    }
    return -1;
}

void sortPoints(Point* points, int numPoints){
    sort(points, points + numPoints, comparex);
};

Point* farthestPointsFromOrigin(Point* points, int numPoints){
    map<double, Point> distances;
    for(int i = 0; i < numPoints; ++i){
        distances.insert(pair<double, Point>(distance(points[i], Point(0, 0)), points[i]));
    }
    map<double, Point>::iterator itr;
    Point *res = new Point[10];
    int i = 0;
    for(itr = --distances.end(); itr != --distances.begin(); --itr){
        res[i] = itr->second;
        ++i;
        if(i == 10){
            break;
        }
    }
    return res;
}