
#ifndef FUTBOL_H
#define FUTBOL_H

#include <iostream>
#include <string>

 //declaración de la clase
    class Persona {

    protected:
     std::string nombre;
     std::string apellido;

    public:
     Persona(const std::string& nombre = "Juancito", const std::string& apellido = "Perez");
};

//declaración de clase derivada 
    class Futbolista : public Persona {

     private:
      int NumCamiseta;

    public:
        Futbolista(const std::string& nombre = "Alexander", const std::string& apellido = "Hutton", int NumCamiseta = 10);
      void Imprimir();
};

#endif
