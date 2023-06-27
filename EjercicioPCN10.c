#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
	HANDLE hSerial;
	DCB dcbSerialParams = { 0 };
	char comando[2];
	DWORD bytesWritten, bytesRead;
	
	// Abrir el puerto serie
	hSerial = CreateFile("COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if (hSerial == INVALID_HANDLE_VALUE) {
		printf("Error al abrir el puerto serie.\n");
		return 1;
	}
	
	// Configurar los parametros del puerto serie
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams)) {
		printf("Error al obtener los parametros del puerto serie.\n");
		CloseHandle(hSerial);
		return 1;
	}
	
	// Configurar los parametros del puerto serie
	dcbSerialParams.BaudRate = CBR_9600;  // Configurar la velocidad de baudios
	dcbSerialParams.ByteSize = 8;         // Configurar el tamano de byte
	dcbSerialParams.StopBits = ONESTOPBIT;// Configurar el numero de bits de parada
	dcbSerialParams.Parity = NOPARITY;    // Configurar la paridad
	
	if (!SetCommState(hSerial, &dcbSerialParams)) {
		printf("Error al configurar los parametros del puerto serie.\n");
		CloseHandle(hSerial);
		return 1;
	}
	
	int i;
	for (i = 0; i < 2; i++) {
		// Enviar comandos al Arduino
		printf("Ingrese un comando ('E' para encender, 'A' para apagar): ");
		scanf("%s", comando);
		
		// Enviar el comando al Arduino
		if (!WriteFile(hSerial, comando, strlen(comando), &bytesWritten, NULL)) {
			printf("Error al enviar el comando al Arduino.\n");
			CloseHandle(hSerial);
			return 1;
		}
		
		// Esperar la respuesta del Arduino (ACK)
		char ack;
		if (!ReadFile(hSerial, &ack, sizeof(ack), &bytesRead, NULL)) {
			printf("Error al recibir la respuesta del Arduino.\n");
			CloseHandle(hSerial);
			return 1;
		}
		
		// Mostrar la respuesta del Arduino
		printf("Respuesta del Arduino: %c\n", ack);
		
		// Verificar el ACK
		if (ack != 'A') {
			printf("Error: No se recibio el ACK esperado.\n");
			CloseHandle(hSerial);
			return 1;
		}
	}
	
	// Cerrar el puerto serie
	CloseHandle(hSerial);
	
	return 0;
}
