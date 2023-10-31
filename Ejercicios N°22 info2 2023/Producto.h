#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
public:
    Producto(std::string Nombre = "guiso", int Precio = 450, int Cantidad = 0);

    std::string GetNombre() const;
    int GetPrecio() const;
    int GetCantidad() const;

    Producto& SetNombre(std::string name);
    Producto& SetPrecio(int cost);
    Producto& SetCantidad(int Cant);

    std::string ToString() const;
    double CalcularCostoTotal() const;

protected:
    std::string Nombre;
    int Precio;
    int Cantidad;
};

class NoPerecedero : public Producto {
public:
    NoPerecedero(std::string Nombre = "fideos", int Precio = 200, int Cantidad = 0);
};

class Perecedero : public Producto {
public:
    Perecedero(std::string Nombre = "papa", int Precio = 50, int Cantidad = 0, int Vida = 2);

    double Calcular() const;
    Perecedero& SetVidaUtil(int vidaUtil);

private:
    int Vida;
};

#endif
