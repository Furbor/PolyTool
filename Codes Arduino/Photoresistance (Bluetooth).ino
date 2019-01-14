// Code Arduino pour le fonctionnement de la photorésistance avec l'ajout du Bluetooth

#include <SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);

// Variables
const int capteur_photo = A0;
String prefixe_son = "*S";
String prefixe_texte = "*L";
long int vieuxTemps = millis();

String c0 = "Endroit eclaire";
String c1 = "Endroit peu eclaire : pensez a allumer une lampe si cela continue";
String c2 = "Endroit sombre : veuillez allumer une lampe pour votre securite";

void setup() {
  Serial.begin(9600);
  BlueT.begin(9600); 
}

void loop() {
  int luminosite = analogRead(capteur_photo);
  Serial.println(luminosite);
  if (luminosite<120) {
    Serial.println(c0);
    BlueT.print(prefixe_texte + c0); // Ecriture sur l'appareil connecté en Bluetooth 
  }
  if (luminosite>120 && luminosite<=350) {
    Serial.println(c1);
    BlueT.print(prefixe_texte + c1); // Ecriture sur l'appareil connecté en Bluetooth
  }
  if (luminosite>350) {
    Serial.println(c2);
    BlueT.print(prefixe_texte + c2); // Ecriture sur l'appareil connecté en Bluetooth
    if (millis() - vieuxTemps > 15000) { // Lorsqu'on est trop longtemps dans la condition précédente (au delà  de 15s), on alerte l'utilisateur par le biais d'un buzzer
      BlueT.print("*S");
    }
  }
  delay(200);
}
