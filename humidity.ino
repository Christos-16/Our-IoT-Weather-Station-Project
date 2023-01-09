
#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humidity = 0;
float tempf = 0;


int power = A3;
int GND = A2;


Weather sensor;

void setup()
{
    Serial.begin(9600);   

    pinMode(power, OUTPUT);
    pinMode(GND, OUTPUT);

    digitalWrite(power, HIGH);
    digitalWrite(GND, LOW);

    
    sensor.begin();

}
void loop()
{
   
    getWeather();
    printInfo();
    delay(1000);

}

void getWeather()
{
  
  humidity = sensor.getRH();

 
  tempf = sensor.getTempF();
 
}

void printInfo()
{

  Serial.print("Temp:");
  tempf=(tempf-32)*5/9;
  Serial.print(tempf);
  Serial.print("C, ");

  Serial.print("Humidity:");
  humidity=humidity*2;
  Serial.print(humidity);
  Serial.println("%");
}