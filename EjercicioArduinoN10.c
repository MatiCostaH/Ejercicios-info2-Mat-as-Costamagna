#include <Arduino.h> 
#define PINLED_GPIO 5

void encender(uint8_t pin);
void apagar(uint8_t pin);

void setup() {
  Serial.begin(9600);
  pinMode(PINLED_GPIO, OUTPUT);
}

void loop() {
  size_t n;
  uint8_t letra[1];

  n = Serial.readBytes(letra, 1);
  if (n == 1) {
    switch (letra[0]) {
      case 'E':
        encender(PINLED_GPIO);
        Serial.print("okE\n");
        delay(100);  
        break;
      case 'A':
        apagar(PINLED_GPIO);
        Serial.print("okA\n");
        delay(100);  
        break;
      default:
        Serial.print("error: Comando no válido\n");
        break;
    }
  }
}

void encender(uint8_t pin) {
  digitalWrite(pin, HIGH);
}

void apagar(uint8_t pin) {
  digitalWrite(pin, LOW);
}