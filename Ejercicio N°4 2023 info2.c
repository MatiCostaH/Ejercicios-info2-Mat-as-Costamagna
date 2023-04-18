#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* prototipos */
void baraja( int wMazo[][ 13 ] );
void reparte(const int wMazo[][13], const char *wCara[], int mano[][2], const char *wPalo[]);
void full_house(int mano[][2], const char *wCara[], const char *wPalo[]);
void cinco_palos (int mano[][2], const char *wCara[], const char *wPalo[]);

int main()
{
	/* inicializa el arreglo palo */
	const char *palo[ 4 ] = { "Corazones", "Diamantes", "Treboles", "Espadas" };
	/* inicializa el arreglo cara */
	const char *cara[ 13 ] =
	{ "As", "Dos", "Tres", "Cuatro",
		"Cinco", "Seis", "Siete", "Ocho",
		"Nueve", "Diez", "Joto", "Quina", "Rey" };
	/* inicializa el arreglo mazo */
	int mazo[ 4 ][ 13 ] = { 0 };
	int mano[5][2]; 
	srand( time( 0 ) ); /* semilla del generador de nÃºmeros aleatorios */
	baraja( mazo );
	reparte(mazo, cara, mano, palo);
	full_house(mano, cara, palo);// la función fullhouse permite saber si hay uno, dos pares o un triple, ademas del full house (ambas condiciones)
	cinco_palos(mano,cara,palo);
	return 0; /* indica terminaciÃ³n exitosa */
} /* fin de main */

/* baraja las cartas del mazo */
void baraja( int wMazo[][ 13 ] )
{
	int fila; /* numero de fila */
	int columna; /* numero de columna */
	int carta; /* contador */
	/* elige aleatoriamente un espacio para cada una de las 52 cartas */
	for ( carta = 1; carta <= 52; carta++ ) {
		/* elije una nueva ubicaciÃ³n al azar hasta que encuentra un espacio vacÃ­o */
		do {
			fila = rand() % 4;
			columna = rand() % 13;
		} while( wMazo[ fila ][ columna ] != 0 ); /* fin de do...while */
		/* coloca el nÃºmero de carta en el espacio vacÃ­o del mazo */
		wMazo[ fila ][ columna ] = carta;
	} /* fin de for */
} /* fin de la funciÃ³n baraja */

/* reparte las cartas del mazo */
void reparte(const int wMazo[][13], const char *wCara[], int mano[][2], const char *wPalo[])
{
	int carta; /* contador de cartas */
	int fila; /* contador de filas */
	int columna; /* contador de columnas */
	int contandocartas = 0;
	
	/* reparte cada una de las 52 cartas */
	for ( carta = 1; carta <= 52 && contandocartas<5; carta++ ) {
		/* realiza el ciclo a través de las filas de wMazo */
		for ( fila = 0; fila <= 3; fila++ ) {
			/* realiza el ciclo a través de las columnas de wMazo en la fila actual */
			for ( columna = 0; columna <= 12; columna++ ) {
				/* si el espacio contiene la carta actual, agrega la carta a la mano */
				if ( wMazo[ fila ][ columna ] == carta ) {
					mano[contandocartas][0] = fila; // guarda el índice del palo
					mano[contandocartas][1] = columna; // guarda el índice de la cara
					contandocartas++;
					if(contandocartas == 5){
						printf("Tu mano es:\n");
						int i;
						for (i = 0; i < 5; i++) {
							printf("%s de %s\n", wCara[mano[i][1]], wPalo[mano[i][0]]);
						}
						return;
					} /* fin de if */
				} /* fin de if */
			} /* fin de for */
		} /* fin de for */
	} /* fin de for */
} /* fin de la función reparte */

void full_house(int mano[][2], const char *wCara[], const char *wPalo[]) {
	int contadorcara[13] = {0}; 
	int i;
	for (i = 0; i < 5; i++) {
		contadorcara[mano[i][1]]++;
	}
	int hay_trio = 0;
	int hay_par = 0;
	int hay_four = 0;
	for (i = 0; i < 13; i++) {
		if (contadorcara[i] == 4) {
			hay_trio = 1;
		}
		if (contadorcara[i] == 3) {
			hay_trio = 1;
		}
		if (contadorcara[i] == 2) {
			hay_par ++;
		}
	}
	if (hay_four) {
		printf(" Hiciste un four of a kind!\n");}
	else if (hay_trio && hay_par) {
		printf(" Hiciste Full house!\n");
	} else if (hay_trio) {
		printf("Tienes un trio!\n");
	} else if (hay_par) {
		printf("Cantidad de Pares:%d\n",hay_par);
	}
	else{
		printf("\nsi no sacaste algo mejor que esto estas al horno\n");
	}
	}


void cinco_palos(int mano[][2], const char *wCara[], const char *wPalo[]) {
    int contadorpalo[4] = {0}; 
    int i;
    for (i = 0; i < 5; i++) {
        contadorpalo[mano[1][i]]++;
    }
    int hay_cinco = 0;
    for (i = 0; i < 4; i++) {
        if (contadorpalo[i] == 5) {
            hay_cinco++;
            int j, min_cara = 15, max_cara = 0;
            for (j = 0; j < 5; j++) {
                if (mano[1][j] == i) {
                    int cara = mano[0][j];
                    if (cara < min_cara) {
                        min_cara = cara;
                    	}
                    if (cara > max_cara) {
                        max_cara = cara;
						 }
                }
            }
            if (max_cara - min_cara == 4) {
                printf("Haz sacado una escalera de un palo!\n");
            } else {
                printf("Haz sacado cinco de un palo.\n");
            }
            break;
        }
    }
    if (!hay_cinco) {
        printf("\nNo hay cinco cartas del mismo palo, estas al horno.\n");
    }
}