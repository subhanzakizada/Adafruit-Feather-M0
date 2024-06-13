// Deserializing - taking a JSON and converting to data
// Arduino Json library
#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial) continue;


  // {
  //   "sensor": "gps",
  //   "time": 1351824120,
  //   "data": [
  //     48.756080,
  //     2.302038
  //   ]
  // }
  const char* input = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

  JsonDocument doc; // to store the deserialized document
  deserializeJson(doc, input); 

  // extracting the values
  const char* sensor = doc["sensor"];
  long time = doc["time"];

  JsonArray data = doc["data"];
  double latitude = data[0];
  double longitude = data[1];

  // another way we can do
  // double latitude = doc["data"][0];
  // double longitude = doc["data"][1];


  // printing 
  Serial.println(sensor);
  Serial.println(time);
  Serial.println(latitude);
  Serial.println(longitude);

}

void loop() {
  // put your main code here, to run repeatedly:
}
