// Code Arduino pour le fonctionnement de la photorésistance

int capteur = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int luminosite = analogRead(capteur);
  Serial.println(luminosite);
  if (luminosite>120 && luminosite<=350) {
    Serial.println("Vous êtes dans un endroit peu éclairé ; pensez à allumer une lampe si cela continue");
  }
  if (luminosite>350) {
    Serial.println("Vous êtes dans un endroit sombre ; veuillez allumer une lampe pour votre sécurité");
  }
  delay(200);
}
