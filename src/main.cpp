#include <Arduino.h>

#define TEMP_PIN A0
#define HEATER_PIN 1
#define FAN_PIN 2

int temperature;
String instruction;
void setup() {
  analogReference(INTERNAL); //Zmienia na 1.1V odniesienia
  Serial.begin(9600);
  pinMode(HEATER_PIN,OUTPUT);
  pinMode(FAN_PIN,OUTPUT);

  digitalWrite(HEATER_PIN,LOW);
  digitalWrite(FAN_PIN,LOW);
}



void loop() {
  if (Serial.available() > 0)
  {
    instruction=Serial.readStringUntil('\n');
    if(instruction=="SET FAN")
    {
      digitalWrite(FAN_PIN,HIGH);
    }
    else if(instruction=="RESET FAN")
    {
      digitalWrite(FAN_PIN,LOW);
    }
    else if (instruction=="SET HEATER")
    {
       digitalWrite(HEATER_PIN,HIGH);
    }
    else if (instruction=="RESET HEATER")
    {
       digitalWrite(HEATER_PIN,LOW);
    }
    else if (instruction=="GET TEMP")
    {
       temperature=analogRead(TEMP_PIN);
       Serial.println(temperature);
    } 
  
   delay(1000);
   }
}