#include <Arduino.h>

class Motores {
private:
    int pinesMotor[4];          // Array para los pines
    float delayEntrePasos;

public:
    Motores(int pins[], float delaySteps);
    void Bobina();
    void medio_paso();
};

Motores::Motores(int pins[], float delaySteps) {
    for (int i = 0; i < 4; i++) {
        pinesMotor[i] = pins[i];
        pinMode(pinesMotor[i], OUTPUT);
    }
    delayEntrePasos = delaySteps;
}

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

void Motores::Bobina() {
    // Secuencia de bobina en bobina
    for (int i = 0; i < 5; i++) {
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
}

void Motores::medio_paso() {
    // Secuencia de medio paso
    for (int i = 0; i < 5; i++) {
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
}
