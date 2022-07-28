#include <SoftwareSerial.h>
const byte rx = D3;
const byte tx = D4;
const long int baudrate = 9600;
String message;
SoftwareSerial fpga(rx, tx);

void setup() {
  fpga.begin(baudrate);
  Serial.begin(baudrate);
}

void loop() {
  
  Serial.println("Digite o comando...");
  while(not Serial.available());
  delay(500);
  
  message = "";
  while(Serial.available())
    message += char(Serial.read());
   
  Serial.println("Enviando:" + message);
  fpga.print(message+"\r\n");
  Serial.println("Aguardando 5s para a resposta...");
  
  //  while(not fpga.available());
  delay(5000);
  message = "";
  while(fpga.available()){
    message += char(fpga.read());
  }
    
  Serial.println("Recebido: " + message);
}
