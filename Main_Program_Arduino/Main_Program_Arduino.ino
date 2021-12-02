#include <DS1307.h>
#include <Wire.h>
#include "MMA7660.h"
#include "rgb_lcd.h"
MMA7660 accelmeter;
rgb_lcd lcd;
DS1307 clock;//define a object of DS1307 class

// Variabler
float x, y, z;
int buttonState;
int count = 0;
bool knapnede = false;

int sensorPin = A2;
int sensorValue = 0;
int stateCount = 0;
int yTjek = 0;

//background light variables
int colorR;
int colorG;
int colorB;
int lightAmplifier = 0;

//stopur variables
int secunder;
int minuter;
int timme;

//variebler til random elev funktionen
const char* chosenElev;
const char* classMateList[] = {"Anders","Emil","Fahmi","Freja","Gustav Werk","Gustav Wett","Haris","Ismail","Jabriil","Jakob","Ludvig","Jeppe","Jonatan","Kasper","Lovro","Mathias","Mie","Mohammad","Nelisa","Nicolai","Pernille","Rasmus","Robert","Sarah","Silas","Simon","Thøger","Tobias","Taaha","William"};

//variablerne til temperatur funktionen
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k

String picker = "";

  void setup()
  {
    lcd.begin(16, 2);
    accelmeter.init();
    pinMode(2, INPUT);


    // clock setup
    Serial.begin(9600);
    clock.begin();
    clock.fillByYMD(2021, 11, 18); 
    clock.fillByHMS(8, 52, 00); 
    clock.fillDayOfWeek(THU);
    clock.setTime();//write time to the RTC chip

    // random elev setup
    randomSeed(analogRead(A3));
    pinMode(4, INPUT);
  }

  void loop()
  {
    lightAmplifier = analogRead(A1);
  
    lcd.setRGB(colorR, colorG, colorB);
    colorR = lightAmplifier >> 2;
    colorG = lightAmplifier >> 2;
    colorB = lightAmplifier >> 2;
    
    rotate();
    //buttomCounter();
    lcd.setCursor(0, 1);
    if (stateCount == 1)
    {
      //printTime();
      //lcd.print(stateCount);
    }
    else if (stateCount == 2)
    {
      randomElevMode();
      //lcd.print(stateCount);
    }
    else if (stateCount == 3)
    {
      temperature();
    }
    else if (stateCount == 4)
    {
      stopur();
    }
    
    delay(100);
    lcd.clear();
  }
