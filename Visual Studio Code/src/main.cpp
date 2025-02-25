// Import all the libraries
#include <Arduino.h>
#include <EloquentTinyML.h>
#include <Arduino_HTS221.h>
#include <Arduino_LSM9DS1.h>
#include <Arduino_LPS22HB.h>
#include <Array.h>
#include <model.h>

// Declare the model
#define INPUTS 3
#define OUTPUTS 1
#define Tensor_ARENA 4*1024

Eloquent::TinyML::TfLite<INPUTS,OUTPUTS, Tensor_ARENA> soil_moisture_model;



void setup() {
  Serial.begin(9600);
  soil_moisture_model.begin(model);

  Serial.begin(9600);
  while (!Serial);

  // Initiate the HTS2221 Sensor
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }

  // Initiate the pressure sensor
  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (1);
  }

}

void loop() {
//   Read the sensor readings
 float temperature = HTS.readTemperature();
  float humidity   = HTS.readHumidity();
  float pressure = BARO.readPressure();
 

    float inputs[INPUTS]={temperature,humidity,pressure};
    int outputs=soil_moisture_model.predict(inputs);


  Serial.print("Temperature:");
  Serial.print(temperature);
  Serial.print(',');
  Serial.print(" Humidity:");
  Serial.print(humidity);
  Serial.print(',');
  Serial.print(" Pressure:");
  Serial.print(pressure);
  Serial.print(',');
  Serial.print(" Moisture Level:");
  Serial.print(outputs);
  Serial.println();

 
   delay(3000);

}
