//Code pour le module utilisant l'effet Hall

int sensor = 2;  // le input du sensor est branché su le pin 7
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
volatile int tour;
const float rayon = 0.0004;
float distance;
volatile long vitesse;
float v;
float vm;
float pi=3.14159;
long temps=0;
long delai=1000;
int c;


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
  attachInterrupt(0,compteur,CHANGE);
  //temps=millis();
}

void loop() {
  aimant=analogRead(sensor);
  if (aimant<=515){
    digitalWrite(aimant,LOW);
  }
  else{
    digitalWrite(aimant,HIGH);
  }
  if (millis()>(temps+delai)) {
    temps=temps+delai;
    c=c+1;
    //vitesse=((tour*2*pi)*0,032)*3,6;
    v=v+vitesse;
    vm=v/c;
    distance=(2*pi)*rayon*tour;
    //Serial.print("vitesse instantanée=");
    //Serial.print(vitesse);
    //Serial.println("km/h");
    //Serial.print("vitesse moyenne");
    //Serial.print(vm);
    //Serial.println("km/h");
    //Serial.print("Distance=");
    //Serial.print(distance);
    //Serial.println("km");
  }
  delay(500);
  tour=0;
}

void compteur(){
  tour=tour+1;
  Serial.println(tour);
  Serial.println("Aimant détecté");
  vitesse=((tour*2*pi)*0,032)*3,6;
  Serial.println(vitesse);
}
