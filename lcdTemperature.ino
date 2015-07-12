#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

int temp_add = 72;

byte degreeSymbol[8]
{
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
};
void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();
lcd.print("Temperature");
lcd.createChar(0, degreeSymbol);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Wire.beginTransmission(temp_add);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(temp_add, 1);
  while(Wire.available() == 0);
  int c = Wire.read();
  int f = round(c*9.0/5.0 + 32.0);
  
  lcd.setCursor(0,1);
  lcd.print(c);
  lcd.write((byte)0);
  lcd.print("C,");
  lcd.print (" ");
  lcd.print(f);
 lcd.write((byte)0);
  lcd.println("F      ");
  delay(500);
 
}
