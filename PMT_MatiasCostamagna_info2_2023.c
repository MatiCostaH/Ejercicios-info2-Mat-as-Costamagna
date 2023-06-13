#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//redondear los resultados "%.2", fijarse porque repite 2 veces el comentario final, ajustar la ecuación.
#define PI 3.14159
#define RADIO_CONDUCTO 0.2
void cantidad_de_agua (float* velocidad, float* Caudal);
void Anotaciones(const char* InfoAgregada, const char* texto);

int main(){
	float velocidad;
	float Caudal;
	char respuesta1;
	printf("\n¡bienvenido a la montaña! ¿Quieres pasar?\n");
	
	printf("\npresiona S(si)/N(no)\n");
	scanf(" %c",&respuesta1);   
	
	if(respuesta1 == 'S'|| respuesta1 == 's'){
		
		printf("Aquí arriba estan las mallas que toman Agua de la niebla,\n te dare un ejemplo con esta que tiene 10 mts cuadrados");
		cantidad_de_agua (&velocidad, &Caudal);
		char velocidadStr[20];
		char caudalStr[20];
		snprintf(velocidadStr, 20, "%f", velocidad);
		snprintf(caudalStr, 20, "%f", Caudal);
        printf("\nVamos a dejar esto anotado en mi registro\n");
		Anotaciones("Velocidad del agua:", velocidadStr);
		Anotaciones("Caudal en la tuberia principal:", caudalStr);
		
	}else{
		printf("\nno hay problema, que tengas un buen día!\n");
		return 0;
	}
	return 0;
	
}
	
	void cantidad_de_agua (float* velocidad, float* Caudal){
		int minimo=2;
		int maximo=10;
		int tiempCaida= 20; // en segundos
		
		float volumenAgua = minimo + rand() % (maximo - minimo + 1);
		printf("\ncomo podemos observar, esta mañana junto %f litros\n", volumenAgua);
		
		float area = RADIO_CONDUCTO * RADIO_CONDUCTO * PI;
		*velocidad = volumenAgua/(area * tiempCaida);
		printf("\nVen, vamos a abrir la compuerta del tanque\n");
		printf("\n La velocidad del agua al pasar por aquí es de %f km/h, y tarda %d segundos en vaciarse", *velocidad, tiempCaida);
		*Caudal = (*velocidad/area);
		printf("\n Con todos estos datos podemos saber que %f es el caudal en la tuberia principal\n",*Caudal);
	}
		
		
	void Anotaciones(const char* InfoAgregada, const char* texto) {
    FILE* ptr = fopen("distribucion.txt", "a");

    if (ptr != NULL) {
        fprintf(ptr, "%s: %s\n", InfoAgregada, texto);
        fclose(ptr);
    } else {
        printf("\nParece que me he quedado sin tinta\n");
    }
}
