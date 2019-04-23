void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i = 0; i<3; i++){
     Serial.print(".");
     digitalWrite(13, HIGH);
     delay(100);
     digitalWrite(13, LOW);
     delay(100);
  }

   for(int i = 0; i<3; i++){
     Serial.print("_");
     digitalWrite(13, HIGH);
     delay(200);
     digitalWrite(13, LOW);
     delay(200);
  }

   for(int i = 0; i<3; i++){
     Serial.print(".");
     digitalWrite(13, HIGH);
     delay(100);
     digitalWrite(13, LOW);
     delay(100);
  }

  Serial.println();
  delay(500);
}
