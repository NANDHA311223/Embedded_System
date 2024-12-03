bool irvalue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
irvalue=digitalRead(26);
if(irvalue==0){
  Serial.println("Object detected");
  digitalWrite(2,HIGH);
}
else{
  Serial.println("Object Not detected");
  digitalWrite(2,LOW);
}
}