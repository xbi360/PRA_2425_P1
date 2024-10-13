#include "Circle.h"

Circle::Circle():Shape(),center(0,0),radius(1){};

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius){};

Point2D Circle::get_center()const{
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}
double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if(r<=0){
        std::invalid_argument("Radio debe ser positivo");
    }
    radius = r;
}
void Circle::print(){
    std::cout << "Circle: Center = " << center << ", Radius = " << radius << ", Color = " << get_color() << std::endl;
}
double Circle::area()const{
    return PI * pow(radius,2);
}
double Circle::perimeter()const{
    return 2*PI*radius;
}
void Circle::translate(double incX, double incY){
    Point2D p=get_center();
    p.x+=incX;
    p.y+=incY;
    set_center(p);
}
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle: Center = " << c.center << ", Radius = " << c.radius << ", Color = " << c.get_color();
    return out;
}