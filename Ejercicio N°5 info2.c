#include <Arduino.h>
#define n 3               // En estas lineas se incluyen el "define" y la declaración del arreglo
int leds[n];              
int pulsador =5;         // En estas se declaran algunas variables que nos permiten evitar los números magicos
int tiemp = 500; 
bool estado = 1 ;
bool estado_anterior = 1 ;

void setup(){             // Dentro del setup tenemos principalmente el ciclo for que permite llenar el arreglo con las declaraciones de pines
Serial.begin(9600); 
for(int i = 2;i<=4; i++){
    
    pinMode(i,OUTPUT);
    leds[i-2]= i;

  Serial.printf("%d fue declarado como un pin de salida",i);

}
  pinMode(pulsador, INPUT_PULLUP);   //declaración de pines asociados al pulsador como entrada.
  
}
bool sentidoGiro = false;
 // En el loop encontramos una instrucción "if-else" que permite el funcionamiento de la secuencia de leds.


void loop() {
  estado = digitalRead(pulsador);
  if (estado != estado_anterior) {
    if (estado == LOW) {
      sentidoGiro =!sentidoGiro; // invertir el sentido del giro al presionar el pulsador1
    }
    estado_anterior = estado;
    delay(tiemp);
  }

  if (sentidoGiro == false) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[i], HIGH);
      delay(tiemp);
      digitalWrite(leds[i], LOW);
    }
  } else {
    for (int i = 2; i >= 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(tiemp);
      digitalWrite(leds[i], LOW);
    }
  }
}
