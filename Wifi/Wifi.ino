/*#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX

void setup() {  
  Serial.begin(9600);
  BT1.begin(9600);
}

void loop() {  
  if (BT1.available()){ 
    char c = BT1.read() ;
    Serial.print(c);
  }
  if (Serial.available()){  
    char c = Serial.read();
    BT1.print(c);
  }
}*/
#include <SoftwareSerial.h>

SoftwareSerial esp8266(2, 3);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Started");

  // set the data rate for the SoftwareSerial port
  esp8266.begin(115200);
  esp8266.write("AT\r\n");
  esp8266.write("AT+CWMODE=1");
}

void loop() {
  if (esp8266.available()) {
    Serial.write(esp8266.read());
  }
  if (Serial.available()) {
    esp8266.write(Serial.read());
  }
}
