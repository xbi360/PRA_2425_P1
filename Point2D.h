#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Point2D{
    public: 
        double x;
        double y;
        Point2D(double x=0, double y=0): x(x), y(y){};
        static double distance(const Point2D &a, const Point2D &b){
            return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
        }
        bool operator==( const Point2D &a)const{
            return (x==a.x && y==a.y);
        }
        bool operator!=(const Point2D &a){
            return (x!=a.x || y!=a.y);
        }
        friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
            out<<"("<< p.x <<","<<p.y<<")";
            return out;
        }

};
#endif
