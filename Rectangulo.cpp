// Rectangulo.cpp

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

Rectangulo &Rectangulo::SetX(float CordX) {
    x = CordX;
    return *this;
}

Rectangulo &Rectangulo::SetY(float CordY) {
    y = CordY;
    return *this;
}

Rectangulo &Rectangulo::SetAncho(float a) {
    ancho = a;
    return *this;
}

Rectangulo &Rectangulo::SetLargo(float l) {
    largo = l;
    return *this;
}

Cuadrado  &Cuadrado::SetLado(float valor) {
    ancho = valor;
    largo = valor;
    return *this;
}

double Rectangulo::Area() const {
    return ancho * largo;
}

double Rectangulo::Perimetro() const {
    return (2 * ancho) + (2 * largo);
}

void Rectangulo::Adentro(const Rectangulo& otro_rectangulo) const {
    // Verifica si el rectángulo actual está completamente adentro del otro rectángulo
    if (this->x >= otro_rectangulo.x && this->y >= otro_rectangulo.y &&
        (this->x + this->ancho) <= (otro_rectangulo.x + otro_rectangulo.ancho) &&
        (this->y + this->largo) <= (otro_rectangulo.y + otro_rectangulo.largo)) {
        std::cout << "El rectángulo actual entra completamente adentro del otro rectángulo." << std::endl;
    } else {
        std::cout << "El rectángulo actual no entra completamente adentro del otro rectángulo." << std::endl;
    }
}

// Resto de métodos

// lectura
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
