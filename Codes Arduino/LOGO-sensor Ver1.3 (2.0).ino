//Code pour le module utilisant l'effet Hall

int sensor = 7;  // L'"input" du Sensor est branché sur le l'entrée digitale 7
int aimant = HIGH;  // HIGH signifie qu'il y a un aimant

void setup() {
  pinMode(sensor, INPUT); 
  Serial.begin(9600); // Moniteur série
}

void loop() {
  int aimant=digitalRead(sensor); //Lecture de la valeur
  Serial.println(aimant); // Affichage de la valeur
  if (aimant==LOW) // S'il n'y a pas d'aimant 
  {
    Serial.println("Pas d'aimant détecté");
    delay(200);
  }
  
  else // S'il y a un aimant
  {
    Serial.println("Aimant détecté");
    delay(200);
  }
}
