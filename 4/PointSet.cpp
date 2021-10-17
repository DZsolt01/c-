#include "PointSet.h"



int random_num(int min, int max){
    return rand() % (max - min) + min;
}

bool comparex(Point const & p1, Point const& p2){
    if(p1.getX() < p2.getX()){
        return true;
    }
    return false;
}

bool comparey(Point const & p1, Point const& p2){
    if(p1.getY() < p2.getY()){
        return true;
    }
    return false;
}
bool compareDis(double const & d1, double const& d2){
    if(d1 < d2){
        return true;
    }
    return false;
}

PointSet::PointSet(int n){
    this->n = n;
    srand(time(0));
    for(int i = 0; i < n; ++i){
        points.emplace_back(Point(random_num(0, 1000), random_num(0, 1000)));
    }
    computeDistances();
}

void PointSet::computeDistances(){
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            distances.emplace_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const{
    return *max_element(distances.begin(), distances.end());
}
double PointSet::minDistance() const{
    return *min_element(distances.begin(), distances.end());
}
int PointSet::numDistances() const{
    return distances.size();
}
void PointSet::printPoints() const{
    for(int i = 0; i < n; ++i){
        cout << points[i].getX() << " " << points[i].getY() << endl;
    }
}
void PointSet::printDistances() const{
    for(int i = 0; i < n; ++i){
        cout << distances[i] << endl;
    }
}
void PointSet::sortPointsX(){
    sort(points.begin(), points.end(), comparex);
}
void PointSet::sortPointsY(){
    sort(points.begin(), points.end(), comparey);
}
void PointSet::sortDistances(){
    sort(distances.begin(), distances.end(), compareDis);
}
int PointSet::numDistinctDistances(){
    sortDistances();
    auto uniq = unique(distances.begin(), distances.end());
    return uniq - distances.begin();
}