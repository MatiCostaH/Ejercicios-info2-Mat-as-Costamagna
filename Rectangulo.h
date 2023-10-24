#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
public:
    Rectangulo(float x = 0, float y = 0, float ancho = 1, float largo = 1); //inicialización del constructor

    // Getters de tipo const
    float GetX() const;
    float GetY() const;
    float GetAncho() const;
    float GetLargo() const;

    // Métodos de configuración que devuelven un puntero 'this'
    Rectangulo  &SetX(float CordX);
    Rectangulo  &SetY(float CordY);
    Rectangulo  &SetAncho(float a);
    Rectangulo  &SetLargo(float l);
    // declaración de metodos 
    double Area() const;
    double Perimetro() const;
    void Adentro(const Rectangulo& otro_rectangulo) const;
    void Leer();

private:
    //atributos privados

    float x;
    float y;
    float ancho;
    float largo;
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(float x = 0, float y = 0, float lado = 10) : Rectangulo(x, y, lado, lado) {}

      Cuadrado  &SetLado(float valor);
};


#endif // RECTANGULO_H
