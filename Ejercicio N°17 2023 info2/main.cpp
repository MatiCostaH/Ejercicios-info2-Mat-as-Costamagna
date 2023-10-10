#include <Arduino.h>
#include "Motores.h"

int pinesMotor[] = {5, 6, 7, 8};  // Pines del motor
float retardoEntrePasos = 15.0;    // Retardo entre pasos

Motores motor(pinesMotor, retardoEntrePasos);

void setup() {
    Serial.begin(9600);
}

void loop() {
    motor.Bobina();   // Realiza la secuencia de bobina en bobina con retardos de 1 segundo
    delay(1000);
    motor.medio_paso();
    delay(1000);
}
