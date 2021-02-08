const int in = A0;
const int led [8] = {2,3,4,5,6,7,8,9};

void setup() {
  // put your setup code here, to run once:
  pinMode(in,INPUT);
  for(int i =0;i<8;i++){
    pinMode(led[i],OUTPUT);
  }
  Serial.begin(9600);

}
int ldr;
void loop() {
  // put your main code here, to run repeatedly:
  ldr = analogRead(in);
  if(ldr>200&&ldr<=500){
    nyala(2);
  }
  else if(ldr>500&&ldr<=700){
    nyala(4);
  }
  else if(ldr>700&&ldr<=1000){
    nyala(6);
  }
  else if(ldr>1000){
    nyala(8);
  }
  delay(500);
  Serial.print("LDR :");
  Serial.println(ldr);
}

void nyala(int a){
  for(int i=0;i<8;i++){
    if(i<a){
      digitalWrite(led[i],HIGH);
    }
    else{
      digitalWrite(led[i],LOW);
    }
  }
}
