int in = 7; 
int out = 13;  
int state = HIGH;  
int r;           
int p = LOW;     
void setup()
{
  pinMode(in, INPUT);
  pinMode(out, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  r = digitalRead(in);
  if (r == HIGH && p == LOW) {
    if (state == HIGH){
      state = LOW;
      Serial.println(state);
    }
    else{ 
      state = HIGH;
      Serial.println(state);  
  }
  }
  digitalWrite(out, state);
  p = r;
}
