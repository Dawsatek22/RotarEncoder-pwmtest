// This is a code to control a pwm pin with rotary encoder.
#define encoderOutA 6 // CLK
#define encoderOutB 5 // DT
const int pwm1 = 3; // the pwm pin
int counter = 0;
int State;
int old_State;
void setup() {
  pinMode(pwm1,OUTPUT);
pinMode (encoderOutA, INPUT);
pinMode (encoderOutB, INPUT);
Serial.begin (9600);
//Read First Position of Channel A
old_State = digitalRead(encoderOutA);
}
void loop() {
  digitalWrite(pwm1,counter);
State = digitalRead(encoderOutA);
if (State != old_State)
{
if (digitalRead(encoderOutB) != State)
{
counter ++;
}
else {
counter --;
}
Serial.print("Position: ");
Serial.println(counter);
}
old_State = State; // the first position was changed
}
