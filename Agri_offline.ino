//L293D
//Motor A
const int motorPin1  = 12;  // Pin 14 of L293
const int motorPin2  = 14;  // Pin 10 of L293

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

#define LightSensor 34
#define SoilSensor 35

//This will run only one time.
void setup(){

    Serial.begin(9600);
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);

    pinMode(LightSensor,INPUT);
    pinMode(SoilSensor,INPUT);

    pinMode(DHTPIN,INPUT);
    dht.begin();
}

void TEMP_HUMI_READ() {
  float t = dht.readTemperature();
  //temperature = t;
  float h = dht.readHumidity();
  //humidity = h;
  Serial.print("Temperature: "); Serial.println(t);
  Serial.print("Humidity: "); Serial.println(h);
  delay(250);
}

void MOTOR_RUN(){
  digitalWrite(motorPin1, HIGH);
  delay(5000);
  digitalWrite(motorPin1, LOW);
}

void SOIL_READ(){
  int soilValue = analogRead(SoilSensor);
  soilValue = map(soilValue, 0, 4095, 100, 0);
  Serial.print("Soil Value : ");
  Serial.println(soilValue);
  if(soilValue <=30){
    MOTOR_RUN();
    }
  delay(250);
  }

void LIGHT_READ(){
  int lightValue = analogRead(LightSensor);
  lightValue = map(lightValue, 0, 4095, 100, 0);
  Serial.print("Light Value : ");
  Serial.println(lightValue);
  delay(250);
  }

void loop(){
  //TEMP_HUMI_READ();
  SOIL_READ();
  LIGHT_READ();
  //MOTOR_RUN();
  }
