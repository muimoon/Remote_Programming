#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
// You should get Auth Token in the Blynk App.

DHT dht(2, DHT11);

char auth [] = "67a17b1eafea4f828f444b4298867d05";

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature

}
void setup ()
{
  Serial.begin (9600);
  Blynk.begin (auth , "NOVA_1440", "asdfghjkl");
  dht.begin();
  delay(5000);
  sendSensor();
}
void loop ()
{
  Blynk.run ();
  sendSensor();
  delay(5000);
}
