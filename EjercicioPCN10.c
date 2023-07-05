#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rs232.h"

#define MAX_BUFFER_SIZE 256
#define PUERTO_COM 3
#define BAUDIOS 9600


int main() {
	int bytesWritten, bytesRead;
	int port_num = PUERTO_COM;
	int baudrate = BAUDIOS;
	char mode[] = {'8','N','1',0};
	char buffer[MAX_BUFFER_SIZE];
	char comando[2][512];
	
	strcpy(comando[0], "A");
	strcpy(comando[1], "E");
	
	if (RS232_OpenComport(port_num, baudrate, mode, 0)) {
		printf("No se puede abrir el puerto COM\n");
		return 0;
	}
	
	for (int i = 0; i < 2; i++) {
		// Enviar comandos al Arduino
		printf("Ingrese un comando ('E' para encender, 'A' para apagar): ");
		scanf("%s", comando[i]);
		
		// Enviar el comando al Arduino
		bytesWritten = RS232_SendBuf(port_num, comando[i], strlen(comando[i]));
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
