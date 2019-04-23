  #include <ESP8266WiFi.h>
  #include <WiFiClient.h>
  #include <ThingSpeak.h>

#include <dht.h>
#define dataPin D8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object

  int sensor_pin = A0;
  int pump_pin = D5;

  const char * ssid = "Redmi 5 Plus";
  const char * password = "hello123";
  
  WiFiClient client;
  
  unsigned long myChannelNumber = 763302;
  unsigned long myChannelNumberPump = 763752;
  const char * myWriteAPIKey = "5JQHCPX8GDC11BH7";
  const char * myWriteAPIKeyPump = "MXZ1JMJIY8U7MFP3";
  
  void setup() {
    Serial.begin(115200);
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6,INPUT);
   

    delay(10);
    // Connect to WiFi network  
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    
     
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    // Print the IP address  
    Serial.println(WiFi.localIP());
  
    ThingSpeak.begin(client);//?
  }
  void loop() {
    
    //getting soil moisture D0
    digitalWrite(D0, HIGH);
    int soil_data = analogRead(sensor_pin);
    
    digitalWrite(D0, LOW);
    Serial.print("Mositure : ");
    Serial.print(soil_data);
    Serial.println("");

    //getting water level D1
    digitalWrite(D1, HIGH);
    int water_data = analogRead(sensor_pin);
    digitalWrite(D1, LOW);
    Serial.print("Water Level : ");
    Serial.print(water_data);
    Serial.println("");

    //getting light level D2
    digitalWrite(D2, HIGH);
    int light_data = analogRead(sensor_pin);
    
    digitalWrite(D2, LOW);
    Serial.print("light Level : ");
    Serial.print(light_data);
    Serial.println("");

    //getting the temperature and humidity data Vin pin
    
  
    int readData = DHT.read11(dataPin); // Reads the data from the sensor
    float temp_data = DHT.temperature; // Gets the values of the temperature
    float humid_data = DHT.humidity; // Gets the values of the humidity
     
    // Printing the results on the serial monitor
    Serial.print("Temperature = ");
    Serial.print(temp_data);
    Serial.print(" *C ");
    Serial.print("    Humidity = ");
    Serial.print(humid_data);
    Serial.println(" % ");
    

    // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  

    // soil data in field 1
    ThingSpeak.writeField(myChannelNumber, 1, soil_data, myWriteAPIKey);

    // water data in field 2
    ThingSpeak.writeField(myChannelNumber, 2, water_data, myWriteAPIKey);

    // light data in field 3
    ThingSpeak.writeField(myChannelNumber, 3, light_data, myWriteAPIKey);

    // temperature data in field 4
    ThingSpeak.writeField(myChannelNumber, 4, temp_data, myWriteAPIKey);

    // humidity data in field 5
    ThingSpeak.writeField(myChannelNumber, 5, humid_data, myWriteAPIKey);

    int pumpdata = ThingSpeak.readIntField (myChannelNumberPump, 1);  
    Serial.print(pumpdata);
    
    if(pumpdata==1){
      digitalWrite(D5, HIGH);
      delay(10000);
      digitalWrite(D5, LOW);
      ThingSpeak.writeField(myChannelNumberPump, 1, 0, myWriteAPIKeyPump);
      
    }
    
    delay(20000); // ThingSpeak will only accept updates every 15 seconds.  
  }
