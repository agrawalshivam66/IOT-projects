int in = 7;
int out = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(in,INPUT);
pinMode(out,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int reading = digitalRead(in);
if(reading==HIGH){
  digitalWrite(out,HIGH);
}
else{
  digitalWrite(out,LOW);
}
}
