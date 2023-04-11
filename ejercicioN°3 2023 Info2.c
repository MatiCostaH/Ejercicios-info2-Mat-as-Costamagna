
#include <stdio.h>
#define TAMANIO 10

int main()
{
    /* inicializa a */
    int a[ TAMANIO ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
    int pasadas; /* contador de pasadas */
    int i; /* contador de comparaciones */
    int almacena; /* ubicación temporal utilizada para el intercambio de elementos */
    int detector;
    printf( "Elementos de datos en el orden original\n" );

    /* muestra el arreglo original */
    for ( i = 0; i < TAMANIO; i++ ) {
        printf( "%4d", a[ i ] );
    } /* fin de for */

    /* ordenamiento burbuja */
    /* ciclo para controlar el número de pasos */
    for ( pasadas = 1; pasadas < TAMANIO; pasadas++ ) {
        /* ciclo para controlar el número de comparaciones por pasada */
        detector= 0;
        for ( i = 0; i < TAMANIO - 1; i++ ) {
            /* compara los elementos adyacentes y los intercambia si el primer
            30 elemento es mayor que el segundo */
            if ( a[ i ] > a[ i + 1 ] ) {
                almacena = a[ i ];
                a[ i ] = a[ i + 1 ];
                a[ i + 1 ] = almacena;
                detector = 1;
            } /* fin de if */
        } /* fin del for interno */
        if(detector==0){
            break;
        }
    } /* fin del for externo */

    printf( "\nElementos de datos en orden ascendente\n" );
    /* muestra el arreglo ordenado */
    for ( i = 0; i < TAMANIO; i++ ) {
    printf( "%4d", a[ i ] );
    } /* fin de for */

    printf( "\n" );
    return 0; /* indica terminación exitosa */
}