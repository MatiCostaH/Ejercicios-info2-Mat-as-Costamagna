#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rs232.h"

#define MAX_BUFFER_SIZE 256

int main() {
	int port_num = 3;  // Número del puerto COM a utilizar
	char comando[2];
	unsigned char buffer[MAX_BUFFER_SIZE];
	int bytesWritten, bytesRead;
	int i;
	
	// Abrir el puerto serie
	if (RS232_OpenComport(port_num, 9600) != 0) {
		printf("Error al abrir el puerto serie.\n");
		return 1;
	}
	
	for (i = 0; i < 2; i++) {
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