bool irvalue=26;
void setup() {
  // put your setup code here, to run once:
pinMode(26,INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
\
irvalue=digitalRead(26);
if(irvalue==1)
Serial.println("touch");
else
Serial.println("not touch");
}