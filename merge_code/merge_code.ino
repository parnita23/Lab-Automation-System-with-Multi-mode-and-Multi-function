#include<LiquidCrystal.h>
LiquidCrystal lcd(11,12,14,15,16,17);
int current_status;
int DTMF_Code;
char c;
int digitalPin =3;
float val = 0;
char PhoneNo[]="+918999340126";
//int buzzerpin=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(A5,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
 // pinMode(7,OUTPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(4000);
  lcd.begin(16, 2);
  delay(1000);
  
  lcd.setCursor(0, 1);
  lcd.print(" GSM DTMF test... ");
  Serial.begin(9600);
  delay(1000);
  Serial.println("AT");
  delay(300);
  Serial.println("ATS0=1");
  delay(300);
  Serial.println("AT+DDET=1,1000,0,0");
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(digitalPin);
 
  if(val<1000)
  {
      lcd.setCursor(1,0);
      lcd.print("door closed: ");
      //digitalWrite(buzzerpin,LOW);
    } 
     else
    {
      lcd.setCursor(1,0);
      lcd.print("door opened: ");
      //digitalWrite(buzzerpin,HIGH);
       Serial.println("AT+CMGF=1\r\n");
   delay(1000);
    Serial.println("AT+CMGS=\"+918999340126\"\r\n");
   delay(1000);
     
      Serial.print("koi aaya hai");
      delay(1000);
      Serial.print(char(26));
   Serial.write(0x1A);
    }
  Serial.println("AT+CPAS");
  delay(100);
  if(Serial.find("+CPAS: "))
  {
    char c=Serial.read();
    current_status=c-48;
    if(current_status==0)
    {
      lcd.setCursor(0,1);
      lcd.print("Waiting for call...");
    }
    if(current_status==3)
    {
      lcd.setCursor(0,1);
      lcd.print("ringing....");
      delay(3000);
    }
    if(current_status==4)
    {
      lcd.setCursor(0,1);
      lcd.print("call Received....");
      if(Serial.find("+DTMF:"))
      {
        DTMF_Code=Serial.parseInt();

        switch(DTMF_Code)
        {
          case 1:
          digitalWrite(8,HIGH);
          lcd.setCursor(0,1);
          lcd.print("DTMF:1 R1:ON");
          break;
          case 2:
          digitalWrite(8,LOW);
          lcd.setCursor(0,1);
          lcd.print("DTMF:2 R1:OFF");
          break;
          case 3:
          digitalWrite(9,HIGH);
          lcd.setCursor(0,1);
          lcd.print("DTMF:3 R2:ON");
          break;
          case 4:
          digitalWrite(9,LOW);
          lcd.setCursor(0,1);
          lcd.print("DTMF:4 R2:OFF");
          break;
          case 5:
          digitalWrite(10,HIGH);
          lcd.setCursor(0,1);
          lcd.print("DTMF:5 R3:ON");
          break;
          case 6:
          digitalWrite(10,LOW);
          lcd.setCursor(0,1);
          lcd.print("DTMF:6 R3:OFF");
          break;
          case 7:
          digitalWrite(2,HIGH);
          digitalWrite(3,LOW);
          lcd.setCursor(0,1);
          lcd.print("CLOCKWISE");
          break;

          case 8:
          digitalWrite(2,LOW);
          digitalWrite(3,HIGH);
          lcd.setCursor(0,1);
          lcd.print("ANTICLOCKWISE");
          break;
          case 9:
          digitalWrite(2,LOW);
          digitalWrite(3,LOW);
          lcd.setCursor(0,1);
          lcd.print("STOP");
          break;
          }
       }
      delay(100);
    }
  }
  delay(100);
    
}
