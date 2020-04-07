#include<LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);

const int buttonPin=2;
const int PotentioPin=A4;

int buttonState=0;
int mode;
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(A4,INPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
lcd.begin(16,2);
//delay(1000);
//d.print("= MODE =");
}

void loop() {
  // put your main code here, to run repeatedly:
if(mode==0)
{
val=analogRead(PotentioPin);
delay(1000);

  if(val<300)
  {
    lcd.clear();
    mode=1;//L
    //delay(1000);
    lcd.setCursor(0,1);
    lcd.print(" Miss ");//H
    delay(1000);
    
  }
if(val>300 && val<=700)
{
   lcd.clear();
 mode=2;
 //delay(1000);
    lcd.setCursor(0,1);
    lcd.print(" GSM ");
    delay(2000);
   
}
if(val>700)
{
   lcd.clear();
  mode=3;
 // delay(1000);
    lcd.setCursor(0,1);
    lcd.print(" GPS ");
    delay(1000);
   
}
}
if(digitalRead(buttonPin)==LOW)
{
  if(mode==1)
  {
     lcd.setCursor(0,1);
    lcd.print("Mode 1..");
    delay(1000);
  }
  if(mode==2)
  {
     lcd.setCursor(0,1);
    lcd.print("Mode 2.");
    delay(1000);
  }
  if(mode==3)
  {
     lcd.setCursor(0,1);
    lcd.print("Mode 3.");
    delay(1000);
  }
}
else
{
  mode=0;
}
}
