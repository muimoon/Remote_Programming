#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth [] = "67a17b1eafea4f828f444b4298867d05";
void setup ()
{
  Serial.begin (9600 );
  Blynk.begin (auth , "Tenda_06C908", "Mykiso123");
}
void loop ()
{
  Blynk.run ();
}

