#include <iostream>

class Rectangulo {                                                         
public:
    Rectangulo(float x, float y, float ancho = 1, float largo = 1)
        : x(x), y(y), ancho(ancho), largo(largo) {}

    double Area() {
        return ancho * largo;
    }

    double Perimetro() {
        return (2 * ancho) + (2 * largo);
    }

    void Setear(float CordX, float CordY, float a, float l) {
        x = CordX;
        y = CordY;
        ancho = a;
        largo = l;
    }

    void leer() {
        std::cout << "Ingrese la coordenada x: ";
        std::cin >> x;

        std::cout << "Ingrese la coordenada y: ";
        std::cin >> y;

        std::cout << "Ingrese el ancho: ";
        std::cin >> ancho;

        std::cout << "Ingrese el largo: ";
        std::cin >> largo;
    }

private:
    float x;
    float y;
    float ancho;
    float largo;
};

int main() {
    Rectangulo rect(0, 0); // Crear un rectángulo con coordenadas (0, 0) y valores predeterminados de ancho y largo

    rect.leer(); // Configurar los valores del rectángulo a través del método leer

    std::cout << "Área del rectángulo: " << rect.Area() << std::endl;
    std::cout << "Perímetro del rectángulo: " << rect.Perimetro() << std::endl;

    return 0;
}
