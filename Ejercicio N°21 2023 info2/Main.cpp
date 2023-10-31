#include <iostream>
#include "Empleado.h"

int main() {
    // Crear un empleado, configurarlo y aplicar el plus
    Empleado juan;
    juan.SetNombre("Roberto").SetApellido("Lescano").SetEdad(35);
    juan.plus();
    std::cout << "Salario de Juan: $" << juan.GetPlus() << std::endl;

    // Crear un empleado de tipo comercial, configurarlo y aplicar el plus
    Comercial ana;
    ana.SetNombre("Ana").SetApellido("Liza").SetEdad(40).SetComision(26000);
    ana.plus();
    std::cout << "Salario de Ana (Comercial): $" << ana.GetPlus() << std::endl;

    // Crear un empleado de tipo repartidor, configurarlo y aplicar el plus
    Repartidor carlos;
    carlos.SetNombre("Aquiles").SetApellido("Bailo").SetEdad(23).SetZona(3);
    carlos.plus();
    std::cout << "Salario de Carlos (Repartidor): $" << carlos.GetPlus() << std::endl;

    return 0;
}