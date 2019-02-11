//Second code pour le module utilisant l'effet Hall (Séance du Lundi 11 Février 2019)

//definition du module bluetooth
#include <SoftwareSerial.h>
#define RX 12
#define TX 11
SoftwareSerial BlueT(RX,TX);


int sensor = A0;  // Input du sensor est branché sur le pin 2
int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
volatile float tour;
const float rayon = 0.32; // Rayon de la roue (cherchée sur Google)
float distance;
volatile long vitesse;
float v;
float pi=3.14159;
unsigned long temps;
long delai=1000;
int compteurV; // Compteur


String prefixe_1 = "*V";
String prefixe_2 = "*D";


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
  BlueT.begin(9600);
  attachInterrupt(0,compteur,RISING);
  temps=millis(); 
}

void loop() {
  aimant=digitalRead(sensor);
  //Serial.println(aimant);
  
  if (millis()>temps+delai) {
    //Serial.print("Tour du 'if' : ");
    tour=tour/2;
    Serial.println(tour);
    //Serial.println(aimant);
    temps=temps+delai;
    compteurV=compteurV+1;
    vitesse=(tour*60)*pi*rayon*2/60;
    distance=distance+(2*pi)*rayon/1000*tour;
    BlueT.print(prefixe_1+"Vitesse instantanee : "+vitesse+"km/h");
    BlueT.print(prefixe_2+"Distance parcourue : "+distance+"km");
    tour=0;
  }
}

void compteur(){
  delay(delai);
  tour=tour+1;
  //Serial.print("Tour n°");
  //Serial.println(int(tour));  
}
