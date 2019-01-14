// Code Arduino pour le fonctionnement de la photorésistance


// Variables
const int capteur = A0;
String c1 = "Endroit peu éclairé : pensez à allumer une lampe si cela continue";
String c2 = "Endroit sombre : veuillez allumer une lampe pour votre sécurité";

void setup() {
  Serial.begin(9600);
}

void loop() {
  int luminosite = analogRead(capteur);
  Serial.println(luminosite);
  if (luminosite>120 && luminosite<=350) {
    Serial.println(c1);
  }
  if (luminosite>350) {
    Serial.println(c2);
  }
  delay(200);
}
