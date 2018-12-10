//Code pour le module utilisant l'effet Hall

int sensor = 7;  // le input du sensor est branché su le pin 7
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  aimant=digitalRead(sensor);
  if (aimant==LOW)
  {
    Serial.println("Aimant détecté");
    delay(100);
  }
  else
  {
    Serial.println("Pas d'aimant détecté");
    delay(100);
  }
}

//Problème : un aimant est toujours détecté, même lorsqu'il y en a pas.
