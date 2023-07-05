#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rs232.h"

#define MAX_BUFFER_SIZE 256

int main() {
  int CantidadByte;
  int puertoCOM= 3;             //Número de puerto. 4 es para el COM3 en windows
  int baudios=9600;            //Velocidad en baudios
  char modo[]={'8','N','1',0}; // 8 bits de datos, no paridad, 1 bit de parada
  char Recepcion[LONG_BUFFER];
  char str[2][512];

   strcpy(str[0], "A");
  strcpy(str[1], "E");

  if(RS232_OpenComport(puertoCOM, baudios, modo, 0)) //Prueba abrir el puerto, devuelve 1 en caso de error
  {
    printf("No se puede abrir el puerto COM\n");
    return(0);
  }

	for (int i = 0; i < 2; i++) {
		// Enviar comandos al Arduino
		printf("Ingrese un comando ('E' para encender, 'A' para apagar): ");
		scanf("%s", comando);
		
		// Enviar el comando al Arduino
		bytesWritten = RS232_SendBuf(port_num, comando, strlen(comando));
		if (bytesWritten < 0) {
			printf("Error al enviar el comando al Arduino.\n");
			RS232_CloseComport(port_num);
			return 1;
		}
		
		// Esperar la respuesta del Arduino (ACK)
		bytesRead = RS232_PollComport(port_num, buffer, MAX_BUFFER_SIZE);
		if (bytesRead < 0) {
			printf("Error al recibir la respuesta del Arduino.\n");
			RS232_CloseComport(port_num);
			return 1;
		}
		
		// Mostrar la respuesta del Arduino
		printf("Respuesta del Arduino: %c\n", buffer[0]);
		
		// Verificar el ACK
		if (buffer[0] != 'A' && buffer[0] != 'E') {
			printf("Error: No se recibió el ACK esperado.\n");
			RS232_CloseComport(port_num);
			return 1;
		}
	}
	
	// Cerrar el puerto serie
	RS232_CloseComport(port_num);
	return 0;
}
