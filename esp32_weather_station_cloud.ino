#include <WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"

// 1. Your Phone Hotspot Credentials
const char* ssid = "YOUR_WIFI_SSID";    // Make sure capitalization matches your phone exactly!
const char* password = "YOUR_WIFI_PASSWORD"; // Your hotspot password

// 2. Your ThingSpeak Channel Details
unsigned long myChannelNumber = xxxxx; 
const char* myWriteAPIKey = "YOUR_THINGSPEAK_API_KEY"; 

// 3. Sensor Pin Config
#define DHTPIN 23     // Matches your working D23 pin
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  // Connect to your mobile hotspot
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  
  ThingSpeak.begin(client);
}

void loop() {
  // Read sensor data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Update the Serial Monitor locally
  Serial.print("Temp: "); Serial.print(temperature); Serial.print("°C | ");
  Serial.print("Hum: "); Serial.print(humidity); Serial.println("%");

  // Package data for ThingSpeak (Field 1 = Temp, Field 2 = Humidity)
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  
  // Write data to the cloud
  int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
  if(responseCode == 200){
    Serial.println("Cloud update successful!");
  } else {
    Serial.print("Error updating cloud. HTTP Code: ");
    Serial.println(responseCode);
  }
  
  // ThingSpeak requires at least a 15-second delay between updates on free accounts
  delay(20000); 
}