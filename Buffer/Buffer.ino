#include <SoftwareSerial.h>
const byte rx = D2;
const byte tx = D3;
String message;
SoftwareSerial fpga(rx, tx);

void setup() {
  fpga.begin(9600);
  Serial.begin(9600);
}

void loop() {
  while(not Serial.available());
  
  delay(500);
  
  message = "";
  while(Serial.available())
    message += char(Serial.read());
    
  fpga.print(message);
  
  delay(500);
  
  message = "";
  while(fpga.available())
    message += char(fpga.read());
  
  Serial.println("Recebido: " + message);
}
