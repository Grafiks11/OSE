#include <Arduino.h>

float temperature;
float setTemperature=22;
int tempPin = 0;
int heater =1;
int fan =2;
String instruction;
void setup() {
  analogReference(INTERNAL); //Zmienia na 1.1V odniesienia
  Serial.begin(9600);
  pinMode(heater,OUTPUT);
  pinMode(fan,OUTPUT);

  digitalWrite(heater,LOW);
  digitalWrite(fan,LOW);
}



void loop() {
  if (Serial.available() > 0)
  {
    instruction=Serial.readStringUntil('\n');
    if(instruction=="SET FAN")
    {
      digitalWrite(fan,HIGH);
    }
    else if(instruction=="RESET FAN")
    {
      digitalWrite(fan,LOW);
    }
    else if (instruction=="SET HEATER")
    {
       digitalWrite(heater,HIGH);
    }
    else if (instruction=="RESET HEATER")
    {
       digitalWrite(heater,LOW);
    }
    else if (instruction=="GET TEMP")
    {
       temperature=analogRead(tempPin);

        //przeliczanie temp
        //temperature=Vin/(10)=ADCresult*Vref/(1024*10)
        temperature=temperature*1100/(1024*10); 
        Serial.write((byte)temperature);
    } 
  
   delay(1000);
   }
}