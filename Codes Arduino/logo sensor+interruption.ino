//Code pour le module utilisant l'effet Hall

int sensor = A0;  // Input du sensor est branché sur le pin 2
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
volatile int tour;
const float rayon = 0.0004; // Rayon de la roue (choisi arbitrairement)
float distance;
volatile long vitesse;
float v;
float vm; // Vitesse moyenne
float pi=3.14159;
long temps=0;
long delai=1000;
int c; // Compteur


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
  attachInterrupt(0,compteur,RISING);
  //temps=millis();
}

void loop() {
  aimant=analogRead(sensor);
  if (millis()>(temps+delai)) {
    temps=temps+delai;
    c=c+1;
    vitesse=((tour*2*pi)*0,032)*3,6;
    v=v+vitesse;
    vm=v/c;
    distance=(2*pi)*rayon*tour;
    Serial.print("Vitesse instantanée: ");
    Serial.print(vitesse);
    Serial.println("km/h");
    //Serial.print("Vitesse moyenne: ");
    //Serial.print(vm);
    //Serial.println("km/h");
    //Serial.print("Distance parcourue: ");
    //Serial.print(distance);
    //Serial.println("km");
  }
  delay(500);
  tour=0;
}

void compteur(){
  tour=tour+1;
  Serial.print("Tour n°");
  Serial.println(tour);
  
}
