#include <iostream>
#include "Rectangulo.h"

int main() {
    Rectangulo rect(0, 0); // Crear un rectángulo con coordenadas (0, 0) y valores predeterminados de ancho y largo

    rect
        ->SetX(2.0)
        ->SetY(3.0)
        ->SetAncho(4.0)
        ->SetLargo(5.0); // Utilizar llamadas en cascada para configurar los valores del rectángulo

    std::cout << "Coordenada x del rectángulo: " << rect.GetX() << std::endl;
    std::cout << "Coordenada y del rectángulo: " << rect.GetY() << std::endl;
    std::cout << "Ancho del rectángulo: " << rect.GetAncho() << std::endl;
    std::cout << "Largo del rectángulo: " << rect.GetLargo() << std::endl;

    std::cout << "Área del rectángulo: " << rect.Area() << std::endl;
    std::cout << "Perímetro del rectángulo: " << rect.Perimetro() << std::endl;

    return 0;
}
