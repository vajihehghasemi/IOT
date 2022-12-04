//DC Motor 1 control                                             
#define ENABLE 5
#define DIRA 3

// Humidity Sensor
#include <dht.h>
#define DHT11_PIN 2
dht DHT;
// int i;
 int H=85;
 int T=30;
 double Humid  , New_H , New_T;
 double Temp;
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("Automatic cooler Designed by Vajihe Ghasemi\n\n");
  delay(1000);
}
void loop() {

    DHT.read11(DHT11_PIN);
    delay(200);
    New_H = DHT.humidity;
    delay(200);
    New_T = DHT.temperature;
    if(New_H>0){
      Humid = New_H;
      }
    if( New_T>0){
    Temp = New_T;
    }
    Humid = New_H;
    Temp = New_T;
    Serial.print("Current humidity = ");
    Serial.print(Humid);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(Temp); 
    Serial.println("C  ");
    if (Humid>= 0 && (Humid>=H||Temp>=T)){
            while(true){
                        Serial.println(" Cooling...");
                        digitalWrite(ENABLE,HIGH); // enable on
                        digitalWrite(DIRA,HIGH);
 
                        delay(200);
                        DHT.read11(DHT11_PIN);
                        Serial.print("Current humidity = ");
                        Serial.print(Humid);
                        Serial.print("%  ");
                        Serial.print("temperature = ");
                        Serial.print(Temp); 
                        Serial.println("C  ");
                        delay(1000);
                        if (Humid<=H&&Temp<=T){
                              digitalWrite(ENABLE,LOW); // disable
                              break;
}
                      New_H = DHT.humidity;
                     delay(100);
                      New_T = DHT.temperature;
                      
                       if(New_H>0){
                        Humid = New_H;
                          }
                        if( New_T>0){
                       Temp = New_T;
                       }
            }
