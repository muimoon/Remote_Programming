//DHT11 And NodeMCU With Blynk
//My GitHub https://github.com/manoranjan2050
//My Hackster.io https://www.hackster.io/Manoranjan2050
//This Video Link https://youtu.be/0dbws1i2GoE
#define BLYNK_PRINT Serial

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth [] = "67a17b1eafea4f828f444b4298867d05";

#define DHTPIN 0          // D3
 
// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}

void setup ()
{
  Serial.begin (9600 );
  //Blynk.begin (auth , "Tenda_06C908", "Mykiso123");
  //Blynk.begin (auth , "Bunny_house", "asdfghjkl");
  Blynk.begin (auth , "ChinaNet-hcr7", "nkdaspqr");

  dht.begin();
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

}

void loop ()
{
  Blynk.run ();
}
