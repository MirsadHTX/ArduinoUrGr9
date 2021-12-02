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

String randomElev(){
picker = listElev[random(0,32)];
return picker;
}
*/

void randomElevMode() {
  //this is the function responsible for the random class mate picker
  if(digitalRead(4) == true){
    chosenElev = classMateList[random(0, 30)];
    delay(10);
  }
  
  lcd.clear();
  lcd.print(chosenElev);
  delay(50);
}

void temperature() {
  int a = analogRead(A0);
  float R = 1023.0/a-1.0;
  R = R0*R;
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;

  lcd.print(temperature);
}

void stopur() {
  secunder += 1;

  if(secunder > 59) {
    secunder = 0;
    minuter += 1;
  }

  if(minuter > 59) {
    minuter = 0;
    timme += 1;
  }

  lcd.print(timme);
  lcd.print(":");
  lcd.print(minuter);
  lcd.print(":");
  lcd.print(secunder);

  delay(900);
}
