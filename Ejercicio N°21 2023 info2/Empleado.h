#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string> 

class Empleado {
public:
    Empleado(std::string nombre = "Jacinto", std::string apellido = "Lopez", int edad = 45);

    Empleado &SetNombre(const std::string& nombre);
    Empleado &SetApellido(const std::string& apellido);
    Empleado &SetEdad(int edad);

    int GetPlus() const;

    virtual void plus();

private:
    std::string Nombre;   
    std::string Apellido; 
    int Edad;
    int Plus;
};

class Comercial : public Empleado {
public:
   
    Comercial(std::string nombre = "Jacinto", std::string apellido = "Lopez", int edad = 45, double comision = 0.0);

    Comercial& SetComision(double comision);

    void plus() override;

    double GetComision() const;

private:
    double Comision;
};

class Repartidor : public Empleado {
public:
    Repartidor(std::string nombre = "Carlos", std::string apellido = "Gonzalez", int edad = 30, int zona = 1);

    Repartidor& SetZona(int zona);

    void plus() override;

    int GetZona() const;

private:
    int Zona;
};

#endif
