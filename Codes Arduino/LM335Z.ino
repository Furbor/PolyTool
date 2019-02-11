// Code pour le capteur de température LM335Z

int capteurPin =  A0;    // Port analogique pour lire la température

void setup() {
  Serial.begin(9600);
  }

void loop() { 
  int tensionAnalogique = analogRead(capteurPin); // Lecture de la tension 
  float tension = (tensionAnalogique * 5.0) / 1024.0; //Conversion en volt
  float temperature = ((tensionAnalogique*5.0)/10.24)-273.15;

  Serial.print(tension);
  Serial.println(" V");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
  }
