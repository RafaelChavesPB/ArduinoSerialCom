#include <SoftwareSerial.h>
const byte rx = D2;
const byte tx = D3;
byte it = 0;
SoftwareSerial fpga(rx, tx);

void setup() {
  fpga.begin(9600);
  Serial.begin(9600);
}

void loop() {
  fpga.print(char(++it));
  Serial.print("Sending another byte: ");
  Serial.println(it, DEC);
  delay(500);
  while(fpga.available()){
    byte c = fpga.read();
    Serial.print("Receiving a byte: ");
    Serial.println(c, DEC); 
    Serial.println("");
  }
  delay(2000);
}
