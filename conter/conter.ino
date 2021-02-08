#include <LiquidCrystal.h>
#include <SevSeg.h>
SevSeg svg;
LiquidCrystal lcd(7,6,9,10,11,12);
const int in [2] = {3,4};
void setup() {
  // put your setup code here, to run once:
  byte svg1 = 1;
  byte svg2[]={};
  byte pin[] = {14,15,16,17,18,19,20,21};
  svg.begin(COMMON_ANODE,svg1,svg2,pin,true);
  svg.setBrightness(80);
  for(int i = 0;i<2;i++){
    pinMode(in[i],INPUT);
  }
  lcd.begin(16,2);
}
int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  if(digitalRead(in[0])&&digitalRead(in[1])){
    i--;
    if(i<0){
      i=9;
    }
    lcd.print("Hitung turun :");
    lcd.print(i);
  }
  else if(digitalRead(in[0])){
    i++;
    if(i>9){
      i=0;
    }
    lcd.print("Hitung naik :");
    lcd.print(i);
  }
  else if(digitalRead(in[1])){
    i--;
    if(i<0){
      i=9;
    }
    svg.setNumber(i);
    svg.refreshDisplay();
  }
  else{
    i++;
    if(i>9){
      i=0;
    }
    svg.setNumber(i);
    svg.refreshDisplay(); 
  }
  delay(1000);
  lcd.clear();
  delay(500);
  
}
