#include <WiFiClient.h>
#include <WiFi.h>
#include <ThingSpeak.h>

const int pirPin = 5;   // PIR sensor connected to GPIO5 (D1)
const int relayPin = 12; // Relay connected to GPIO12 (D2)
unsigned long lastMotionTime = 0;
const unsigned long motionTimeout = 10000; // 10 seconds
int motionCount = 0; // Count of motions detected
unsigned long totalLightOnTime = 0; // Accumulated light ON time
const float powerRating = 10.0; // Light power in Watts

const char* ssid = "Wokwi-GUEST";  
const char* password = "";  
unsigned long myChannelNumber = 2898713;
const char* myWriteAPIKey = "3ML9KFOY5VGEX1FB";
WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Initially, light is OFF

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  
  if (motionDetected) {
    digitalWrite(relayPin, HIGH); // Turn ON light
    lastMotionTime = millis();
    motionCount++; // Increment motion count
    Serial.println("Motion detected! Light ON");
  }

  // If no motion for 10 seconds, turn off light
  if (millis() - lastMotionTime > motionTimeout) {
    if (digitalRead(relayPin) == HIGH) { 
      totalLightOnTime += motionTimeout / 1000; // Accumulate ON time in seconds
    }
    digitalWrite(relayPin, LOW); // Turn OFF light
    Serial.println("No motion. Light OFF");
  }

  // Calculate energy consumption (Watt-hours)
  float energyConsumption = (powerRating / 3600.0) * totalLightOnTime;

  // Send data to ThingSpeak every 15 seconds
  static unsigned long lastUpdateTime = 0;
  if (millis() - lastUpdateTime >= 15000) {
    lastUpdateTime = millis();

    int lightStatus = digitalRead(relayPin);
    ThingSpeak.setField(1, lightStatus);
    ThingSpeak.setField(2, motionCount);
    ThingSpeak.setField(3, (int)totalLightOnTime);
    ThingSpeak.setField(4, energyConsumption);
    
    int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if (status == 200) {
      Serial.println("Data sent to ThingSpeak successfully!");
    } else {
      Serial.println("Error sending data to ThingSpeak.");
    }
    
    motionCount = 0; // Reset motion count after sending data
  }

  delay(100); // Short delay to prevent excessive looping
}
