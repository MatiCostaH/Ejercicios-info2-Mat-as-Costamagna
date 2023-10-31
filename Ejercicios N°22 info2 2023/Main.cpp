#include <iostream>
#include "Producto.h"

int main() {
    NoPerecedero noPerecedero("arroz", 200, 2);
    NoPerecedero noPerecedero2("fideos", 100, 2);
    Perecedero perecedero("manzanas", 50, 2, 2);
    Perecedero perecedero2("bananas", 60, 2, 1);

    std::cout << "Datos del producto: " << noPerecedero.ToString() << std::endl;
    double costoTotal1 = noPerecedero.CalcularCostoTotal();
    std::cout << "El precio de vender 2 productos es: $" << costoTotal1 << std::endl;

    std::cout << "Datos del producto: " << noPerecedero2.ToString() << std::endl;
    double costoTotal2 = noPerecedero2.CalcularCostoTotal();
    std::cout << "El precio de vender 2 productos es: $" << costoTotal2 << std::endl;

    std::cout << "Datos del producto: " << perecedero.ToString() << std::endl;
    double costoTotal3 = perecedero.Calcular();
    std::cout << "El precio de vender 2 productos es: $" << costoTotal3 << std::endl;

    std::cout << "Datos del producto: " << perecedero2.ToString() << std::endl;
    double costoTotal4 = perecedero2.Calcular();
    std::cout << "El precio de vender 2 productos es: $" << costoTotal4 << std::endl;

    double precioTotal = costoTotal1 + costoTotal2 + costoTotal3 + costoTotal4;
    std::cout << "El precio total de vender 2 productos de cada tipo es: $" << precioTotal << std::endl;

    return 0;
}
