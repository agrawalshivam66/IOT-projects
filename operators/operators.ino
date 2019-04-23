void setup() {
  // put your setup code here, to run once:
  int a = 7;
  int b = 5;
 
  Serial.begin(9600);
  Serial.print("a=");
  Serial.println(a);
  Serial.println(a+b);
  Serial.println(a-b);
  Serial.println(a*b);
  Serial.println(a/b);
  Serial.println(a%b);
  Serial.println(a==b);
  Serial.println(a>b);
  Serial.println(a<b);
  Serial.println(a>=b);
  Serial.println(a<=b);

Serial.println(a&b);
Serial.println(a|b);
Serial.println(a++);
Serial.println(b--);
Serial.println(a+=b);
Serial.println(a-=b);
Serial.println(a*=b);
 Serial.println(a/=b);
Serial.println(a>>2);
Serial.println(a<<2);

   
 
}
 long time;

void loop() {
  // put your main code here, to run repeatedly:


  delay(1000);
time = millis();
  Serial.println(time);
}
