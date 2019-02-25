/* Programme final pour le projet PolyTool associant tous les modules fonctionnels à ce jour (25/02/2019)
et alliant le Bluetooth pour l'envoi des données sur le téléphone */

// Code pour le module Bluetooth
#include <SoftwareSerial.h>
#define RX 12
#define TX 11
SoftwareSerial BlueT(RX,TX);

// Bibliothèques pour le Pulse sensor
#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>

// Variables pour les modules
const byte DHT11 = 5;
const int capteur_photo = A0;
int sensor = A1;
const int pulse_sensor = A2; 
PulseSensorPlayground pulseSensor;

// Code d'erreur de la fonction readDHT11() et readDHT22()
const byte DHT_SUCCESS = 0;        // Pas d'erreur
const byte DHT_TIMEOUT_ERROR = 1;  // Temps d'attente dépassé
const byte DHT_CHECKSUM_ERROR = 2; // Données reçues erronées




// Préfixe pour l'utilisation du Bluetooth
String prefixe_H = "*H"; //humidité
String prefixe_T = "*T"; //température
String prefixe_son = "*S"; //son
String prefixe_texte = "*L"; //luminosité
String prefixe_V = "*V"; //vitesse
String prefixe_D = "*D"; //distance
String prefixe_bpm = "*B"; //rythme cardiaque

// Autres variables
  // Pour le DHT11
    float temperature, humidity;
  // Pour la photorésistance
    long int vieuxTemps = millis();
    String c0 = "Endroit eclaire";
    String c1 = "Endroit peu eclaire : pensez a allumer une lampe si cela continue";
    String c2 = "Endroit sombre : veuillez allumer une lampe pour votre securite";
  // Pour le LOGO-sensor
    int aimant = HIGH;  // HIGH signifie qu'il n'y a pas d'aimant
    volatile float tour;
    const float rayon = 0.32; // Rayon de la roue (cherché sur Google)
    float distance;
    volatile long vitesse;
    float v;
    float pi=3.14159;
    unsigned long temps;
    long delai=1000;
  // pour le Pulse sensor
    int Threshold = 225; //Seuil pour déterminer à partir de combien on compte qu'il s'agit d'un battement

void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  pinMode(DHT11, INPUT_PULLUP);
  pinMode(sensor, INPUT);
  attachInterrupt(0,compteur,RISING);
  pulseSensor.analogInput(pulse_sensor); 
  pulseSensor.setThreshold(Threshold);   
  if (pulseSensor.begin()) {
    BlueT.print(prefixe_bpm + "'Pulse sensor' prêt à l'emploi !");
  }
  delay(100);
  temps=millis(); 
}

void loop() { 
  // Pour DHT11
  // Lecture de la température et de l'humidité, avec gestion des erreurs
  switch (readDHT11(DHT11, &temperature, &humidity)) {
  case DHT_SUCCESS: 
     
    // Affichage de la température et du taux d'humidité
    BlueT.print(prefixe_H+F("Humidite (%): ")+humidity);
    BlueT.print(prefixe_T+F("Temperature (^C): ")+temperature);
    break;
 
  case DHT_TIMEOUT_ERROR: 
    Serial.println(F("Pas de reponse !")); 
    break;
 
  case DHT_CHECKSUM_ERROR: 
    Serial.println(F("Pb de communication !")); 
    break;
  }
  // Pour la photorésistance
  int luminosite = analogRead(capteur_photo);
  Serial.println(luminosite);
  if (luminosite<120) {
    Serial.println(c0);
    BlueT.print(prefixe_texte + c0); // Ecriture sur l'appareil connecté en Bluetooth 
  }
  if (luminosite>120 && luminosite<=350) {
    Serial.println(c1);
    BlueT.print(prefixe_texte + c1); // Ecriture sur l'appareil connecté en Bluetooth
  }
  if (luminosite>350) {
    Serial.println(c2);
    BlueT.print(prefixe_texte + c2); // Ecriture sur l'appareil connecté en Bluetooth
    if (millis() - vieuxTemps > 15000) { // Lorsqu'on est trop longtemps dans la condition précédente (au delà  de 15s), on alerte l'utilisateur par le biais d'un buzzer
      BlueT.print("*S");
    }
  }

  // Pour le LOGO-sensor
  aimant=digitalRead(sensor);
  if (millis()>temps+delai) {
    tour=tour/2;
    temps=temps+delai;
    vitesse=(tour*60)*pi*rayon*2/60;
    distance=distance+(2*pi)*rayon/1000*tour;
    BlueT.print(prefixe_V+"Vitesse instantanee : "+vitesse+"km/h");
    BlueT.print(prefixe_D+"Distance parcourue : "+distance+"km");
    tour=0;
  }

  // Pour le Pulse sensor
  int BPM = pulseSensor.getBeatsPerMinute();  
  if (pulseSensor.sawStartOfBeat()) {                                    
    BlueT.print(prefixe_bpm + "BPM : " + String(BPM));                        
  }
  delay(1000);
}

// Interruption pour le DHT11
 // Lit la température et le taux d'humidité mesuré par le capteur DHT11.
 
byte readDHT11(byte pin, float* temperature, float* humidity) {
  
  // Lit le capteur
  byte data[5];
  byte ret = readDHTxx(pin, data, 18, 1000);
  
  // Détecte et retourne les erreurs de communication
  if (ret != DHT_SUCCESS) 
    return ret;
    
  //Calcul de la vraie valeur de la température et de l'humidité
  *humidity = data[0];
  *temperature = data[2];

  return DHT_SUCCESS;
}

// Fonction bas niveau permettant de lire la température et le taux d'humidité (en valeurs brutes) mesuré par un capteur DHTxx.
byte readDHTxx(byte pin, byte* data, unsigned long start_time, unsigned long timeout) {
  data[0] = data[1] = data[2] = data[3] = data[4] = 0;
  // start_time est en millisecondes
  // timeout est en microsecondes
 
  // Conversion du numéro de broche Arduino en ports / masque binaire "bas niveau"
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  volatile uint8_t *ddr = portModeRegister(port);   // Registre MODE (INPUT / OUTPUT)
  volatile uint8_t *out = portOutputRegister(port); // Registre OUT (écriture)
  volatile uint8_t *in = portInputRegister(port);   // Registre IN (lecture)
  
  // Conversion du temps de timeout en nombre de cycles processeur
  unsigned long max_cycles = microsecondsToClockCycles(timeout);
 
  // Evite les problèmes de pull-up
  *out |= bit;  // PULLUP
  *ddr &= ~bit; // INPUT
  delay(100);   // Laisse le temps à la résistance de pullup de mettre la ligne de données à HIGH
 
  // Réveil du capteur
  *ddr |= bit;  // OUTPUT
  *out &= ~bit; // LOW
  delay(start_time); /* Temps d'attente à LOW causant le réveil du capteur
  N.B: Il est impossible d'utilise delayMicroseconds() ici car un délai
  de plus de 16 millisecondes ne donne pas un timing assez précis. */
  
  // Portion de code critique - pas d'interruptions possibles
  noInterrupts();
  
  // Passage en écoute
  *out |= bit;  // PULLUP
  delayMicroseconds(40);
  *ddr &= ~bit; // INPUT
 
  // Attente de la réponse du capteur
  timeout = 0;
  while(!(*in & bit)) { // Attente d'un état LOW
    if (++timeout == max_cycles) {
        interrupts();
        return DHT_TIMEOUT_ERROR;
      }
  }
    
  timeout = 0;
  while(*in & bit) { // Attente d'un état HIGH
    if (++timeout == max_cycles) {
        interrupts();
        return DHT_TIMEOUT_ERROR;
      }
  }

  // Lecture des données du capteur (40 bits)
  for (byte i = 0; i < 40; ++i) {
 
    // Attente d'un état LOW
    unsigned long cycles_low = 0;
    while(!(*in & bit)) {
      if (++cycles_low == max_cycles) {
        interrupts();
        return DHT_TIMEOUT_ERROR;
      }
    }

    // Attente d'un état HIGH
    unsigned long cycles_high = 0;
    while(*in & bit) {
      if (++cycles_high == max_cycles) {
        interrupts();
        return DHT_TIMEOUT_ERROR;
      }
    }
    
    // Si le temps haut est supérieur au temps bas c'est un "1", sinon c'est un "0"
    data[i / 8] <<= 1;
    if (cycles_high > cycles_low) {
      data[i / 8] |= 1;
    }
  }
  
  // Fin de la portion de code critique (en cas d'erreur)
  interrupts();
 
  /*
   * Format des données :
   * [1, 0] = humidité en %
   * [3, 2] = température en degrés Celsius
   * [4] = checksum (humidité + température)
   */
   
  // Vérifie la checksum
  byte checksum = (data[0] + data[1] + data[2] + data[3]) & 0xff;
  if (data[4] != checksum)
    return DHT_CHECKSUM_ERROR; // Erreur de checksum
  else
    return DHT_SUCCESS; // Pas d'erreur de checksum
}

// Interruption pour le LOGO-sensor

void compteur(){
  delay(delai);
  tour=tour+1;  
  Serial.print("Tour n°");
  Serial.println(int(tour));
}
