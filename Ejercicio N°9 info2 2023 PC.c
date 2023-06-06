#include <stdio.h>

typedef struct
{
    char ident_tipo;
    int dato;
    unsigned long intervalo;
} Sensores;

int main() {

    FILE* archivo = fopen("test.txt", "rb");

    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    Sensores temperatura;

    fread(&temperatura, sizeof(Sensores), 1, archivo);

    printf("Datos leídos del archivo:\n");
    printf("Identificador: %c\n", temperatura.ident_tipo);
    printf("Dato: %d\n", temperatura.dato);
    printf("Intervalo: %lu\n", temperatura.intervalo);

    fclose(archivo);

    return 0;
}