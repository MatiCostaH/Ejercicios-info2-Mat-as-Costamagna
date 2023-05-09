void setup(){
DDRD = 0xFF; 
DDRB = 0xFF; // el puerto B se habilito como salida ya que lo use para conectar los transistores
}

void loop() {
 PORTD = B11111110; // Controla los segmentos del primer display
  delay(250);
  PORTD = B11111101;
  delay(250);
  PORTD = B11111011;
  delay(250);
  PORTD = B11110111;
  delay(250);
  PORTD = B11101111;
  delay(250);
  PORTD = B11011111;
  delay(250);
  PORTD = B10111111;
  delay(250);
  PORTD = B01111111;
  delay(250);

                   
  PORTD = 0x00;           // Apaga el primer display
  delay(1);

  PORTD = B11111110;     // Controla los segmentos del segundo display
  PORTD = B11111110;
  delay(250);
  PORTD = B11111101;
  delay(250);
  PORTD = B11111011;
  delay(250);
  PORTD = B11110111;
  delay(250);
  PORTD = B11101111;
  delay(250);
  PORTD = B11011111;
  delay(250);
  PORTD = B10111111;
  delay(250);
  PORTD = B01111111;
  delay(250);

  PORTD = 0x00;           // Apaga el segundo display        
  delay(1);
}