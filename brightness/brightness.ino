int brightness = 0;
void setup() {
  pinMode(11, OUTPUT);
    
}

void loop() {
   analogWrite(11 , brightness);
   delay(100);
   brightness++;
}
