#include "Shape.h"

Shape::Shape():color("rojo"){};


Shape::Shape(std::string color_){
    set_color(color);
}

std::string Shape::get_color()const{
    return color;
}
void Shape::set_color(std::string c){
    if((c!="red" && c!="blue" && c!="green")){
        std::invalid_argument("Introduce un color valido");
    }
    color=c;
}
