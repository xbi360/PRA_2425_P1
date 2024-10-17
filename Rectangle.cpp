#include "Rectangle.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

// Constante para el número de vértices
const int Rectangle::N_VERTICES = 4;

// Constructor por defecto: inicializa el rectángulo con vértices predeterminados
Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);  // v0
    vs[1] = Point2D(1, 0.5);   // v1
    vs[2] = Point2D(1, -0.5);  // v2
    vs[3] = Point2D(-1, -0.5); // v3
}

// Método para verificar si los vértices proporcionados forman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double a1 = Point2D::distance(vertices[0], vertices[1]);
    double a2 = Point2D::distance(vertices[2], vertices[3]);
    double a3 = Point2D::distance(vertices[0], vertices[3]);
    double a4 = Point2D::distance(vertices[1], vertices[2]);

    // Verifica si las longitudes de los lados opuestos son iguales
    return (a1 == a2) && (a3 == a4);
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor: libera la memoria dinámica reservada
Rectangle::~Rectangle() {
    delete[] vs;
}

// Sobrecarga del operador << para imprimir el rectángulo
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectangle vertices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << "(" << r.vs[i].x << ", " << r.vs[i].y << ") ";
    }
    return out;
}
//Método constructor dado los vertices y el color
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    vs = new Point2D[N_VERTICES];
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Método para establecer los vértices del rectángulo
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los puntos no forman un rectángulo");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Sobrecarga del operador [] para obtener un vértice
Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}

// Método para trasladar el rectángulo
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Implementación del método para imprimir información sobre el rectángulo
void Rectangle::print() {
    std::cout << *this << std::endl;
}

// Implementación del método para calcular el área del rectángulo
double Rectangle::area() const {
    double b = Point2D::distance(vs[0], vs[1]); // Longitud de la base
    double h = Point2D::distance(vs[0], vs[3]); // Longitud de la altura
    return b * h;
}

// Implementación del método para calcular el perímetro del rectángulo
double Rectangle::perimeter() const {
    double b = Point2D::distance(vs[0], vs[1]); // Longitud de la base
    double h = Point2D::distance(vs[0], vs[3]); // Longitud de la altura
    return 2 * (b + h);
}

// Sobrecarga del operador de asignación para hacer una copia profunda
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this == &r) return *this;  // Evitar la autoasignación

    delete[] vs;  // Liberar la memoria existente

    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
    return *this;
}

//obtener un vértice específico según el índice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}
