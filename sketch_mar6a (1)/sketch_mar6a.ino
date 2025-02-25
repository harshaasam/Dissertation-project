#include <Arduino_HTS221.h>   // Temperature and Humidity sensor
#include <Arduino_LPS22HB.h>  // Pressure sensor




void setup() { 
  Serial.begin(9600); 
  while (!Serial);

  // Initiate the HTS221 Sensor
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
  // read all the sensor values
  float temperature = HTS.readTemperature(); 
  float humidity = HTS.readHumidity(); 
  float pressure = BARO.readPressure(); 

  
 


  Serial.print(temperature); 
  Serial.print(','); 
  Serial.print(humidity); 
  Serial.print(','); 
  Serial.print(pressure); 
  Serial.print(',');
  Serial.println(analogRead(A7));
   

  // wait 3 seconds before printing again
  delay(3000); 
}
