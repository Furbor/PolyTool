#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>     

//  Variables
const int sensor = 0;              
int Threshold = 550;           
                               
PulseSensorPlayground pulseSensor;  

void setup() {   

  Serial.begin(9600);          

  
  pulseSensor.analogInput(sensor);         
  pulseSensor.setThreshold(Threshold);   
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");
  }
}



void loop() {

 int BPM = pulseSensor.getBeatsPerMinute();  

if (pulseSensor.sawStartOfBeat()) {            
 Serial.print("BPM: ");                        
 Serial.println(BPM);                        
}

  delay(20);                    

}
