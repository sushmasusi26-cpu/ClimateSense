#include <DHT.h>

// -------- Sensor Pins --------
#define DHTPIN 2
#define DHTTYPE DHT11

#define SOIL_PIN A0
#define RAIN_PIN A1
#define WATER_LEVEL_PIN A2

#define LED_PIN 7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);

  Serial.println("ClimateSense - Micro Climate Monitoring Started");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int soilRaw = analogRead(SOIL_PIN);
  int rainRaw = analogRead(RAIN_PIN);
  int waterRaw = analogRead(WATER_LEVEL_PIN);

  // Convert soil moisture to percentage
  int soilPercent = map(soilRaw, 1023, 0, 0, 100);

  Serial.println("------ Sensor Data ------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Soil Moisture: ");
  Serial.print(soilPercent);
  Serial.println(" %");

  Serial.print("Rain Value: ");
  Serial.println(rainRaw);

  Serial.print("Water Level: ");
  Serial.println(waterRaw);

  // -------- Climate Risk Logic --------
  
  // Drought Risk
  if (soilPercent < 30 && temperature > 35) {
    Serial.println("⚠ ALERT: Drought Risk Detected!");
    digitalWrite(LED_PIN, HIGH);
  }

  // Flood Risk
  else if (rainRaw < 400 && waterRaw > 700) {
    Serial.println("⚠ ALERT: Possible Flood Risk!");
    digitalWrite(LED_PIN, HIGH);
  }

  // Cold Stress
  else if (temperature < 15) {
    Serial.println("⚠ ALERT: Sudden Temperature Drop!");
    digitalWrite(LED_PIN, HIGH);
  }

  else {
    Serial.println("✅ Climate Conditions Normal");
    digitalWrite(LED_PIN, LOW);
  }

  Serial.println("--------------------------\n");

  delay(5000);  // 5 seconds delay
}
