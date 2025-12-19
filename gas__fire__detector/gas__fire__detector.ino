#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int GasPin  = 2;
int FirePin = 3;
int buzzer  = 4;

void setup()
{
  pinMode(GasPin, INPUT);
  pinMode(FirePin, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  // رسالة بداية
  lcd.setCursor(0,0);
  lcd.print("System Ready");
  lcd.setCursor(0,1);
  lcd.print("Monitoring...");

  noTone(buzzer);   
  delay(2000);
  lcd.clear();
}

void loop()
{
  bool gas  = (digitalRead(GasPin)  == HIGH); 
  bool fire = (digitalRead(FirePin) == LOW);  

  lcd.clear();
  lcd.setCursor(0,0);

  if (gas || fire)
  {
    if (gas && fire)
    {
      lcd.print("Gas + Fire!!!");
      tone(buzzer, 5000);
    }
    else if (gas)
    {
      lcd.print("Gas Detected!");
      tone(buzzer, 3000);
    }
    else if (fire)
    {
      lcd.print("Fire Detected!");
      tone(buzzer, 3500);
    }
  }
  else
  {
    lcd.print("Safe Now");
    noTone(buzzer);   
  }

  delay(300);
}
