#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
// You should get Auth Token in the Blynk App.
DHT dht(2, DHT11);
char auth[] = "67a17b1eafea4f828f444b4298867d05";

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature

}

void setup( )
{
  //  WiFi.mode(WIFI_OFF);
  //  WiFi.forceSleepBegin();
  //  delay(1);
  Serial.begin(9600);
  dht.begin();
  //  WiFi.forceSleepWake();
  //  delay(1);
  // Disable the WiFi persistence.
  //The ESP8266 will not load and save WiFi settings in the flash memory.
  WiFi.persistent(false);
  Blynk.begin(auth, "NOVA_1440", "asdfghjkl");
}

void loop()
{
  Blynk.run();
  sendSensor();
  delay( 100 );
  //WiFi.disconnect( true );
  // WAKE_RF_DISABLED to keep the WiFi radio disabled when we wake up
  ESP.deepSleep(600000000); //1,000,000 1s
}
