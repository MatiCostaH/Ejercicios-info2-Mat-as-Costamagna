#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char ident_tipo;
    int dato;
    unsigned long intervalo;
} Sensores;

int main() {
    int valor_sensor = 0;
    Sensores temperatura;
    temperatura.ident_tipo = 'A';

    printf("El tamaño ocupado es de: %u bytes\n", sizeof(temperatura)); // Ocupa 12 bits, 5 más que con arduino.
    srand(time(NULL));
    valor_sensor = rand() % 1024;         // simulación del valor arrojado por el sensor.
    temperatura.dato = valor_sensor;

    printf("El valor del sensor es: %d\n", valor_sensor);
    return 0;
}