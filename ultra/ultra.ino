#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,9,10,11,12);
const int ech = 4;
const int trg = 3;
const int out = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(trg,OUTPUT);
  pinMode(ech,INPUT);
  pinMode(out,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  digitalWrite(trg,HIGH);
  delayMicroseconds(10);
  digitalWrite(trg,LOW);
  int t = pulseIn(ech,HIGH);
  float jarak = (0.0034*t)/2;
  if(jarak<30){
    digitalWrite(out,HIGH);
    delay(1000);
    digitalWrite(out,LOW);
    delay(500);
  }
  lcd.print("Jarak : ");
  lcd.print(jarak);
  lcd.print(" cm");
  delay(3000);
  lcd.clear();
  delay(500);
}
