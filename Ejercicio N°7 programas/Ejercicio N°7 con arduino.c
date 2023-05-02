#include <Arduino.h>

typedef struct              // declaración de la estructura
{
    char ident_tipo;
    int dato;
    unsigned long intervalo;
    
}Sensores;
Sensores temperatura;       // uso de la misma
temperatura.ident_tipo = "A"; // asociaremos A a los sensores de temperatura así podremos usar B para humedad, C para movimiento, etc.

void setup() {                                        
 Serial.begin(9600);                         // inicialización del puerto serie y muestra del tamaño ocupado
 Serial.print("el tamaño ocupado es de:");
   sizeof(temperatura); //
  Serial.println(sizeof(temperatura))
  Serial.print("bytes");
}

void loop() {
  unsigned long tiempo_inicio = millis();
  int valor_sensor = analogRead(A0);    // cuerpo del loop para mostrar valores varios
  unsigned long tiempo_fin = millis();
  unsigned long tiempo_intervalo= tiempo_fin - tiempo_inicio;
  temperatura.dato = valor_sensor;
  temperatura.intervalo = tiempo_intervalo;


  Serial.print("El valor del sensor es: ");
  Serial.println(temperatura.dato);
  Serial.print("El tiempo de intervalo es:");
  Serial.println(temperatura.intervalo);

  delay(tiempo_intervalo);
}