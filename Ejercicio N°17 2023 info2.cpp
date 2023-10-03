#include <Arduino.h>

class Motores {
private:
    int pinesMotor[4];          // Array para los pines
    int delayEntrePasos;

public:
    Motores(int pins[], int delaySteps);
    void Bobina(int pasos);
    void medio_paso(int paso);
};

Motores::Motores(int pins[], int delaySteps) {
    for (int i = 0; i < 4; i++) {
        pinesMotor[i] = pins[i];
        pinMode(pinesMotor[i], OUTPUT);
    }
    delayEntrePasos = delaySteps;
    
}

int pinesMotor[] = {5, 6, 7, 8};  // Pines del motor
int retardoEntrePasos = 20;    // Retardo entre pasos

Motores motor(pinesMotor, retardoEntrePasos);

void setup() {
    Serial.begin(9600);
}

void loop() {
    motor.Bobina(int pasos);   // Realiza la secuencia de bobina en bobina con retardos de 2,5 segundos
    delay(2500);
    motor.medio_paso(int paso);
    delay(2500);
}

void Motores::Bobina(int pasos) {
    pasos= 1000;
    for (int i = 0; i < pasos; i++) {
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

void Motores::medio_paso(int paso) {
    paso = 2000;
    for (int i = 0; i < Motores.cantidadPasos ; i++) {
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
