#include <Arduino.h>

#define n 3

int leds[n];
int tiemp = 500;
bool sentidoGiro = false;

// Función de interrupción del pulsador
void pulsInterrupt() {
  sentidoGiro = !sentidoGiro; // Invertir el sentido de giro con el pulsador
}

void setup() {
  Serial.begin(9600);

  for (int i = 4; i <= 6; i++) {
    pinMode(i, OUTPUT);
    leds[i - 4] = i;
    Serial.printf("%d fue declarado como un pin de salida\n", i);
  }

  pinMode(2, INPUT_PULLUP); // Configurar pin 2 como entrada con resistencia de pull-up
  attachInterrupt(digitalPinToInterrupt(2), pulsInterrupt, RISING); // Asociar interrupción al pin 2, detectando flanco de subida
  interrupts(); // Habilitar interrupciones
}

void loop() {
  if (sentidoGiro == false) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[i], HIGH);
      delay(tiemp);
      digitalWrite(leds[i], LOW);
    }
  } else {
    for (int i = 0; i >= 2; i--) {
      digitalWrite(leds[i], HIGH);
      delay(tiemp);
      digitalWrite(leds[i], LOW);
    }
  }
}