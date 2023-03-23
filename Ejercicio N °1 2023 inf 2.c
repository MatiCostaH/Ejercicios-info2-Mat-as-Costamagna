#include <stdio.h>

int main() {
	int n = 100;
	int notas[n];
	int valor;
	int contador = 0;
	int suma = 0;
	
	for(int i=0;i<=n;i++){
		printf("ingrese una nota:");
		scanf("%d",&valor);
		{
		if(valor==9999)
		{break;
		}
		}
		notas[i]=valor;
		contador ++;
	}
	for(int i=0;i<contador;i++){
		suma+= notas[i];
		printf("\n el total de la sumatoria es:%d\n",suma);
	}
	float promedio= suma/contador;
	printf("\n el promedio de los números ingresados es:%f",promedio);
	return 0;
}

