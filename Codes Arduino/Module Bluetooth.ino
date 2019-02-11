//Code pour initiliaser les paramètres du module Bluetooth

#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour - Prêt pour les commandes AT");
  BlueT.begin(9600);
  delay(500);
  }

void loop() {
  while (BlueT.available()) {
    Serial.print(char(BlueT.read()));
    }
  while (Serial.available()) {
    BlueT.write(char(Serial.read()));
    }
}
