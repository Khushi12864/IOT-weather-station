# ESP32 Weather Station ☁️

A mini IoT project that reads real-time temperature and humidity 
data using a DHT11 sensor and streams it to the cloud.

## What it does
- Reads temperature and humidity every 20 seconds
- Sends live data to ThingSpeak for real-time graph visualization
- Monitored locally via Arduino Serial Monitor

## Components Used
- ESP32 Dev Module
- DHT11 Temperature & Humidity Sensor
- Jumper Wires

## Libraries Used
- DHT.h
- WiFi.h
- ThingSpeak.h

## Setup
1. Install the required libraries in Arduino IDE
2. Replace YOUR_WIFI_SSID and YOUR_WIFI_PASSWORD with your credentials
3. Create a ThingSpeak channel and replace YOUR_THINGSPEAK_API_KEY 
   and your channel number
4. Connect DHT11 data pin to D23 on ESP32
5. Upload and open Serial Monitor at 115200 baud

## Learnings
This was my first hands-on IoT project. Faced issues with port 
not found errors, unattached GitHub library links, and a 
potentially fried ESP32 — took 2 days to debug but got there.
