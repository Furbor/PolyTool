//Code pour le module utilisant l'effet Hall

int sensor = 7;  // le input du sensor est branché su le pin 7
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
int tour=0;
const float rayon = 0.0004;
float distance=0;
float vitesse=0;
float v=0;
float vm=0;
const float pi=3.14159;


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
}

void loop() {
  aimant=digitalRead(sensor);
  if (aimant==LOW)
  {
    Serial.println("Aimant détecté");
    //delay(100);
    tour=tour+1;
    vitesse=(((tour/60)*2*pi)*0,032)*3,6;
    v=v+vitesse;
    vm=v/tour;
    distance=distance+(2*pi)*rayon;
  }
  else
  {
    Serial.println("Pas d'aimant détecté");
    //delay(100);
  }
  //distance=distance+(2*pi)*rayon;
  //vitesse=(((tour/60)*2*pi)*0,032)*3,6;
  Serial.print("vitesse instantanée=");
  Serial.print(vitesse);
  Serial.println("km/h");
  Serial.print("vitesse moyenne");
  Serial.print(vm);
  Serial.println("km/h");
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.println("km");
  delay(500);
  
}
