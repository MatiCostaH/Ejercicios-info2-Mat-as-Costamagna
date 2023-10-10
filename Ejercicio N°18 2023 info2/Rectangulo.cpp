#include "Rectangulo.h"
#include <iostream>

Rectangulo::Rectangulo(float x, float y, float ancho, float largo)
    : x(x), y(y), ancho(ancho), largo(largo) {}

float Rectangulo::GetX() const {
    return x;
}

float Rectangulo::GetY() const {
    return y;
}

float Rectangulo::GetAncho() const {
    return ancho;
}

float Rectangulo::GetLargo() const {
    return largo;
}

Rectangulo* Rectangulo::SetX(float CordX) {
    x = CordX;
    return this;
}

Rectangulo* Rectangulo::SetY(float CordY) {
    y = CordY;
    return this;
}

Rectangulo* Rectangulo::SetAncho(float a) {
    ancho = a;
    return this;
}

Rectangulo* Rectangulo::SetLargo(float l) {
    largo = l;
    return this;
}

double Rectangulo::Area() const {
    return ancho * largo;
}

double Rectangulo::Perimetro() const {
    return (2 * ancho) + (2 * largo);
}

void Rectangulo::Leer() {
    std::cout << "Ingrese la coordenada x: ";
    std::cin >> x;

    std::cout << "Ingrese la coordenada y: ";
    std::cin >> y;

    std::cout << "Ingrese el ancho: ";
    std::cin >> ancho;

    std::cout << "Ingrese el largo: ";
    std::cin >> largo;
}
