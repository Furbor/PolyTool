//Code pour le module utilisant l'effet Hall

int sensor = 2;  // le input du sensor est branché su le pin 7
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
volatile long tour;
const float rayon = 0.0004;
float distance;
float vitesse;
float v;
float vm;
const float pi=3.14159;
long temps=0;
long delai=1000;
int c;


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
  attachInterrupt(0,compteur,LOW);
  //temps=millis();
}

void loop() {
  aimant=digitalRead(sensor);
  if (millis()>(temps+delai)) {
    c=c+1;
    vitesse=((((tour*60)/60)*2*pi)*0,032)*3,6;
    v=v+vitesse;
    vm=v/c;
    distance=distance+(2*pi)*rayon;
    Serial.print("vitesse instantanée=");
    Serial.print(vitesse);
    Serial.println("km/h");
    Serial.print("vitesse moyenne");
    Serial.print(vm);
    Serial.println("km/h");
    Serial.print("Distance=");
    Serial.print(distance);
    Serial.println("km");
  }
  delay(500);
}

void compteur(){
  tour=tour+1;
  Serial.println("Aimant détecté");
}
