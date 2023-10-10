#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
public:
    Rectangulo(float x = 0, float y = 0, float ancho = 1, float largo = 1);

    // Getters de tipo const
    float GetX() const;
    float GetY() const;
    float GetAncho() const;
    float GetLargo() const;

    // Métodos de configuración que devuelven un puntero 'this'
    Rectangulo* SetX(float CordX);
    Rectangulo* SetY(float CordY);
    Rectangulo* SetAncho(float a);
    Rectangulo* SetLargo(float l);

    double Area() const;
    double Perimetro() const;
    void Leer();

private:
    float x;
    float y;
    float ancho;
    float largo;
};

#endif // RECTANGULO_H
