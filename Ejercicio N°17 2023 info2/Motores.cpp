#include "Motores.h"
#include <Arduino.h>

Motores::Motores(int pins[], float delaySteps) {
    for (int i = 0; i < 4; i++) {
        pinesMotor[i] = pins[i];
        pinMode(pinesMotor[i], OUTPUT);
    }
    delayEntrePasos = delaySteps;
}

void Motores::Bobina() {
    // Secuencia de bobina en bobina
    digitalWrite(pinesMotor[0], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[0], LOW);

    digitalWrite(pinesMotor[1], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[1], LOW);

    digitalWrite(pinesMotor[2], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[2], LOW);

    digitalWrite(pinesMotor[3], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[3], LOW);
}

void Motores::medio_paso() {
    // Secuencia de medio paso
    digitalWrite(pinesMotor[0], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[1], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[0], LOW);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[2], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[1], LOW);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[3], HIGH);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[2], LOW);
    delay(delayEntrePasos);
    digitalWrite(pinesMotor[3], LOW);
    delay(delayEntrePasos);
}
