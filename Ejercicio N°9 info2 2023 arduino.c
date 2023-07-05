#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File archTiempo;

typedef struct              // declaración de la estructura poner los valores al inicio del setup.
{
    char ident_tipo;
    char relleno;
    int dato;
    unsigned long intervalo;
    
}Sensores;
Sensores temperatura;       // uso de la misma


void setup() {  
temperatura.ident_tipo= 'A'; // asociaremos A a los sensores de temperatura así podremos usar B para humedad, C para movimiento, etc.
temperatura.relleno = 'p';
const int chipSelect = 4;
 Serial.begin(9600);                         // inicialización del puerto serie y muestra del tamaño ocupado
 Serial.print("el tamaño ocupado es de:");
Serial.println(static_cast<int>(sizeof(temperatura)));
  Serial.print("bytes");

  pinMode(SS, OUTPUT);
   
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

   archTiempo = SD.open("test.dat", FILE_WRITE);

 if (archTiempo) {
    Serial.print("Writing to test.txt...");
archTiempo.write((const uint8_t*)&temperatura, sizeof(temperatura));
archTiempo.close();
 }
 else{
   Serial.println("error opening test.txt");
 }

}





// fread((uint8_t)&Sensores,sizeof(Sensores),1,fpt); lectura en pc

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
