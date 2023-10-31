// Empleado.cpp
#include "Empleado.h"

// Implementación del constructor de Empleado
Empleado::Empleado(std::string nombre, std::string apellido, int edad, double salario)
    : Nombre(nombre), Apellido(apellido), Edad(edad), Salario(salario) {}

void Empleado::plus() {
    // No hace nada en la clase base
}

// Implementación de los getters y setters
Empleado& Empleado::SetNombre(const std::string& nombre) {
    Nombre = nombre;
    return *this;
}

Empleado& Empleado::SetApellido(const std::string& apellido) {
    Apellido = apellido;
    return *this;
}

Empleado& Empleado::SetEdad(int edad) {
    Edad = edad;
    return *this;
}

Empleado& Empleado::SetSalario(double salario) {
    Salario = salario;
    return *this;
}

double Empleado::GetSalario() const {
    return Salario;
}

// Implementación de la clase Comercial
Comercial::Comercial(std::string nombre, std::string apellido, int edad, double comision)
    : Empleado(nombre, apellido, edad), Comision(comision) {}

void Comercial::plus() {
    if (Edad > 30 && Comision > 25000) {
        Salario += 5000;
    }
}

Comercial& Comercial::SetComision(double comision) {
    Comision = comision;
    return *this;
}

double Comercial::GetComision() const {
    return Comision;
}

// Implementación de la clase Repartidor
Repartidor::Repartidor(std::string nombre, std::string apellido, int edad, int zona)
    : Empleado(nombre, apellido, edad), Zona(zona) {}

void Repartidor::plus() {
    if (Edad < 25 && Zona == 3) {
        Salario += 5000;
    }
}

Repartidor& Repartidor::SetZona(int zona) {
    Zona = zona;
    return *this;
}

int Repartidor::GetZona() const {
    return Zona;
}
