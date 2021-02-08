#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,9,10,11,12);
const int in = A0;
const int out = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(in,INPUT);
  pinMode(out,OUTPUT);
  lcd.begin(16,2);
}
int rd = 0;
int brg = 0;

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  rd = analogRead(in);
  brg = map(rd,0,1023,0,255);
  lcd.print("Light : ");
  lcd.print(brg);
  lcd.setCursor(0,1);
  if(brg>200){
     lcd.print("terang tae");
  }
  else if(brg<100){
    lcd.print("gelap tae");
  }
  else{
    lcd.print("Normal");
  }
  analogWrite(out,brg);
  delay(1000);
  lcd.clear();
  delay(500);
}
