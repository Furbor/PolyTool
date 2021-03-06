//Code pour le module utilisant l'effet Hall

int sensor = 2;  // Input du sensor est branché sur le pin 2
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
volatile int tour;
const float rayon = 0.0004; // Rayon de la roue (choisi arbitrairement)
float distance;
volatile long vitesse;
float v;
float vm; // Vitesse moyenne
float pi=3.14159;
unsigned long temps;
long delai=1000;
int c; // Compteur


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
  attachInterrupt(0,compteur,RISING);
  
}

void loop() {
  aimant=digitalRead(sensor);
  //Serial.println(aimant);
  temps=millis();
  if (millis()>(temps+delai)) {
    Serial.println(tour);
    Serial.println(aimant);
    temps=temps+delai;
    c=c+1;
    vitesse=(((tour*2)*pi)*0,032)*3,6;
    distance=(2*pi)*rayon*tour;
    //Serial.print("Vitesse instantanée : ");
    //Serial.print(vitesse);
    //Serial.println("km/h");
    
    Serial.print("Distance parcourue : ");
    Serial.print(distance);
    Serial.println("km");
    tour=0;
  }
  
}

void compteur(){
  tour=tour+1;
  Serial.print("Tour n°");
  Serial.println(tour);  
}
