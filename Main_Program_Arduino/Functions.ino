void rotate() 
{
    accelmeter.getAcceleration(&x, &y, &z); // Tager memory address som input
    lcd.clear();
    if (x >= 0.9)
    {
      x = 1;
      lcd.print(x);
    }
    else if (x <= -0.9)
    {
      x = -1;
      lcd.print(x);
    }
    else
    {
      lcd.print(x);
      }
   
    lcd.print(" ");
    if (y >= 0.9)
    {
      y = 1;
      lcd.print(y);
      if (y == 1 && yTjek == 0)
      stateCount = stateCount + 1;
      yTjek = 1;
    }
    else if (y <= -0.9)
    {
      y = -1;
      lcd.print(y);
    }
    else
    {
      lcd.print(y);
      }

    lcd.print(" ");
    if (z >= 0.9)
    {
      z = 1;
      lcd.print(z);
    }
    else if (z <= -0.9)
    {
      z = -1;
      lcd.print(z);
    }
    else
    {
      lcd.print(z);
      }
    yTjek = y;
}

void buttomCounter()
{
    buttonState = digitalRead(2);
    lcd.setCursor(6, 1);
    
    if (buttonState == HIGH) 
    {
    lcd.print("on ");   
      if(buttonState == true && knapnede == false)
      {
        count = count + 1;
      }
        lcd.print(count);
        delay(100);
    } 
    else
    {
    lcd.print("off");
    delay(100);
    }
    knapnede = buttonState;
  }


void printTime() {
    clock.getTime();
    lcd.print(clock.hour, DEC);
    lcd.print(":");
    lcd.print(clock.minute, DEC);
    lcd.print(":");
    lcd.print(clock.second, DEC);
    lcd.print(" ");
    lcd.print(clock.dayOfMonth, DEC);
    lcd.print("/");
    lcd.print(clock.month, DEC);
    lcd.print("/");
    lcd.print(clock.year, DEC);
}
/*
void speaker()
{
  for (let i == 0; i > 2; i ++)
  digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(2,LOW);
  delay(100);
  }
*/
String randomElev(){
picker = listElev[random(0,32)];
return picker;
}
