#define BLYNK_AUTH_TOKEN "vpctDnVuLgfYlvb4_hWCnMiE-iawJ16w"

#define sensor_pin A0 //set A0 pin as sensor pin


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Srishtik";
char pass[] = "Sris2310";

void setup()
{
  Serial.begin(115200); // Set baud rate to 115200
  Blynk.begin(auth, ssid, pass); // connect to blynk server
  pinMode(sensor_pin, INPUT); // configure A0 as input pin
}

void loop()
{
  Blynk.run(); // start blynk server
  int ppm = analogRead(A0); // read sensor value
  Blynk.virtualWrite(V0, ppm); // publish sesnor value to blynk server
  Serial.println(ppm);


// publish air quality to blynk server
  if (ppm < 200){
    Blynk.virtualWrite(V1, "Good Air Quality");
    Serial.println("Good Air Quality");
  }
  else if (ppm > 200 && ppm < 400){
    Blynk.virtualWrite(V1, "Medium Air Quality");
    Serial.println("Medium Air Quality");
  }
  else{
    Blynk.virtualWrite(V1, "Poor Air Quality");
    Serial.println("Poor Air Quality");
  }
  delay(1000);
}
