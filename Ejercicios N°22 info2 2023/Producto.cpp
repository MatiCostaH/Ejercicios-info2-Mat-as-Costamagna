#include "Producto.h"

Producto::Producto(std::string Nombre, int Precio, int Cantidad)
    : Nombre(Nombre), Precio(Precio), Cantidad(Cantidad) {}

NoPerecedero::NoPerecedero(std::string Nombre, int Precio, int Cantidad)
    : Producto(Nombre, Precio, Cantidad) {}

Perecedero::Perecedero(std::string Nombre, int Precio, int Cantidad, int Vida)
    : Producto(Nombre, Precio, Cantidad), Vida(Vida) {}

std::string Producto::GetNombre() const {
    return Nombre;
}

int Producto::GetPrecio() const {
    return Precio;
}

int Producto::GetCantidad() const {
    return Cantidad;
}

Producto& Producto::SetNombre(std::string name) {
    Nombre = name;
    return *this;
}

Producto& Producto::SetPrecio(int cost) {
    Precio = cost;
    return *this;
}

Producto& Producto::SetCantidad(int Cant) {
    Cantidad = Cant;
    return *this;
}

Perecedero& Perecedero::SetVidaUtil(int vidaUtil) {
    Vida = vidaUtil;
    return *this;
}

std::string Producto::ToString() const {
    return "Producto: " + Nombre + ", Precio: $" + std::to_string(Precio) + ", Cantidad: " + std::to_string(Cantidad);
}

double Producto::CalcularCostoTotal() const {
    return static_cast<double>(Precio * Cantidad);
}

double Perecedero::Calcular() const {
    double costoTotal = Precio * Cantidad;

    if (Vida == 1) {
        costoTotal *= 0.25;  // Si queda 1 día para caducar, se reduce 4 veces el costo.
    } else if (Vida == 2) {
        costoTotal *= 0.33;  // Si quedan 2 días para caducar, se reduce 3 veces el costo.
    } else if (Vida == 3) {
        costoTotal *= 0.5;  // Si quedan 3 días para caducar, se reduce a la mitad del costo.
    }

    return costoTotal;
}
