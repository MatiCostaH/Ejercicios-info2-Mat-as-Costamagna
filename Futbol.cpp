#include "futbol.h"

 //constructor de Persona

 Persona::Persona(const std::string& nombre, const std::string& apellido)
    : nombre(nombre), apellido(apellido) {}


 // constructor de Futbolista
 Futbolista::Futbolista(const std::string& nombre, const std::string& apellido, int NumCamiseta)
    : Persona(nombre, apellido), NumCamiseta(NumCamiseta) {}
 
 //implementacion metodo Imprimir
 void Futbolista::Imprimir() {

    std::cout << "Nombre del jugador: " << nombre << std::endl;
    std::cout << "Apellido del jugador: " << apellido << std::endl;
    std::cout << "Número de camiseta: " << NumCamiseta << std::endl;
}
