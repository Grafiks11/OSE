#include <Arduino.h>

#define TEMP_PIN A0
#define HEATER_PIN 1
#define FAN_PIN 2
#define BUFFER_LEN 64

int temperature;
char buffer[BUFFER_LEN];

void setup() {
  analogReference(INTERNAL); //Zmienia na 1.1V odniesienia
  Serial.begin(9600);
  Serial.setTimeout(1000);
  pinMode(HEATER_PIN,OUTPUT);
  pinMode(FAN_PIN,OUTPUT);

  digitalWrite(HEATER_PIN,LOW);
  digitalWrite(FAN_PIN,LOW);
}



void loop() {
  if (Serial.available() > 0)
  {
    Serial.readBytesUntil('\n',buffer,BUFFER_LEN);
    if(strcasecmp(buffer,"SET FAN")==0)
    {
      digitalWrite(FAN_PIN,HIGH);
    }
    else if(strcasecmp(buffer,"RESET FAN")==0)
    {
      digitalWrite(FAN_PIN,LOW);
    }
    else if (strcasecmp(buffer,"SET HEATER")==0)
    {
       digitalWrite(HEATER_PIN,HIGH);
    }
    else if (strcasecmp(buffer,"RESET HEATER")==0)
    {
       digitalWrite(HEATER_PIN,LOW);
    }
    else if (strcasecmp(buffer,"GET TEMP")==0)
    {
       temperature=analogRead(TEMP_PIN);
       Serial.println(temperature);
    }
    memset(buffer,'\0',BUFFER_LEN);
  }
}