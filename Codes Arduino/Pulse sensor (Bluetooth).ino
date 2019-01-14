// Code Arduino pour le fonctionnement du Pulse sensor avec l'ajout du Bluetooth

#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>
#include <SoftwareSerial.h>     

#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);

//  Variables
const int pulse_sensor = A0;              
int Threshold = 225; //Seuil pour déterminer à partir de combien on compte qu'il s'agit d'un battement
String prefixe_bpm = "*B";       
                               
PulseSensorPlayground pulseSensor;  

void setup() {   

  Serial.begin(9600);
  BlueT.begin(9600);          
  pulseSensor.analogInput(pulse_sensor);         
  pulseSensor.setThreshold(Threshold);   
  if (pulseSensor.begin()) {
    BlueT.print(prefixe_bpm + "'Pulse sensor' prêt à l'emploi !");
  }
  delay(100);
}

void loop() {
  int BPM = pulseSensor.getBeatsPerMinute();  
  if (pulseSensor.sawStartOfBeat()) {                                    
    BlueT.print(prefixe_bpm + "BPM : " + String(BPM));                        
  }
  delay(50);                    
}
