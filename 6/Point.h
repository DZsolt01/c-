#include <algorithm>
#include <cmath>

#ifndef POINT_H
    #define POINT_H
    #define M 2000
    class Point{
        private:
            int x, y;
            static int counter;
        public:
            Point( int x=0, int y=0);
            int getX() const;
            int getY() const;
            double distanceTo(const Point& point)const ;
            Point(const Point&);
            ~Point();
            static int getCounter();

    };
#endif /* PONT_H */
