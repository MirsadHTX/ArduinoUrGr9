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
const char* listElev[] = {"Anders","Emil","Fahmi","Freja","Gustav Werk","Gustav Wett","Haris","Ismail","Jabriil","Jakob","Ludvig","Jeppe","Jonatan","Kasper","Lovro","Mathias","Mie","Mohammad","Nelisa","Nicolai","Pernille","Rasmus","Robert","Sarah","Silas","Simon","Thøger","Tobias","Taaha","William"};
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
  }

  void loop()
  {
    rotate();
    //buttomCounter();
    lcd.setCursor(0, 1);
    if (stateCount == 1)
    {
      //printTime();
      lcd.print(stateCount);
    }
    else if (stateCount == 2)
    {
      lcd.print(randomElev());
      lcd.print(stateCount);
      }
    
    delay(100);
    lcd.clear();
  }
