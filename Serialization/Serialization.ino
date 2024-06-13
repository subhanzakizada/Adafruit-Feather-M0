// Serialization
// ArduinoJson 7
#include <ArduinoJson.h> // library installed

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() == 'j') {
    JsonDocument jBuffer;

    jBuffer["day"] = "Monday";

    int temp = 21;
    int humidity = 53;

    jBuffer["temperature"] = temp;
    jBuffer["humidity"] = humidity;

    serializeJson(jBuffer, Serial);
  }
}