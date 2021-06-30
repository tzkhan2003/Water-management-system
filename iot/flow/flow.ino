/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This sketch shows how to write values to Virtual Pins

  NOTE:
  BlynkTimer provides SimpleTimer functionality:
    http://playground.arduino.cc/Code/SimpleTimer

  App project setup:
    Value Display widget attached to Virtual Pin V5
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " _wV9lABMUFvWeRW0AbOf1og1ZV89t9zp";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Mysha";
char pass[] = "tanjim2003";

//my section
const int input = 12;
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  int sensorValue = analogRead(14);
  float voltage = sensorValue * (5.0 / 1024.0);
  Blynk.virtualWrite(V2,voltage );
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000/TIME;
  WATER = FREQUENCY/7.5;
  LS = WATER/60;
  if(FREQUENCY >= 0)
    {
      if(isinf(FREQUENCY))
        {
          Blynk.virtualWrite(V0, 0);
          Blynk.virtualWrite(V1, TOTAL);
          //Blynk.virtualWrite(V0, 10);
          //Blynk.virtualWrite(V1, 50);
        }
      else
      {
        TOTAL = TOTAL + LS;
        Blynk.virtualWrite(V0, WATER);
        Blynk.virtualWrite(V1, TOTAL);
        //Blynk.virtualWrite(V0, 1);
        //Blynk.virtualWrite(V1, 5);
      }
    }   
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
