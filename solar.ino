#include<Servo.h>
int ldr = A0;
int ldr2 = A1;
Servo myservo;
int pos = 90;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
Serial.begin(9600);
myservo.write(pos);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldrvalue = analogRead(ldr);
int ldrvalue2 = analogRead(ldr2);
pos=constrain(pos,0,180);
myservo.write(pos);
if(ldrvalue > 800 and ldrvalue2 < 600){
  pos--;
  myservo.write(pos);
}
else if(ldrvalue < 600 and ldrvalue2 > 800 ){
  pos++;
  myservo.write(pos);
}
int poss=myservo.read();
Serial.print(ldrvalue  ); Serial.print("   "); Serial.print(ldrvalue2); Serial.print("   "); Serial.println(poss);

delay(10);
}
