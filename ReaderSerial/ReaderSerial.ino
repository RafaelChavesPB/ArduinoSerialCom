#include <SoftwareSerial.h>
const byte rx = D2;
const byte tx = D3;
SoftwareSerial fpga(rx, tx);

void setup() {
  fpga.begin(9600);
  Serial.begin(9600);
}

void loop() {
  while(fpga.available()){
    byte c = fpga.read();
    Serial.println(c, BIN); 
    Serial.println(c, HEX); 
  }
  delay(2000);
}
