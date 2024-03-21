/*
  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int avgsensor;
  int sensor;
  int sensor1;
  int sensor2;
  bool relay;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#define relayPin  2
#define wet 230
#define dry 550

void setup() {
  Serial.begin(9600);
  delay(1500);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  onSensorChange();
  onSensor1Change();
  onSensor2Change();
  onAvgsensorChange();
  }

void onSensorChange() {
  sensor = analogRead(A0);
  sensor = map(sensor, dry, wet, 0, 130);
}

void onSensor1Change()  {
  sensor1 = analogRead(A1);
  sensor1 = map(sensor1, dry, wet, 0, 100);
}

void onSensor2Change()  {
  sensor2 = analogRead(A2);
  sensor2 = map(sensor2, dry, wet, 0, 100);
}

void onAvgsensorChange()  {
  avgsensor = (sensor + sensor1 + sensor2) / 3;
  if (relay) {
    if (avgsensor > 60) {
      digitalWrite(relayPin, LOW);
    }
    else if (avgsensor < 60) {
      digitalWrite(relayPin, HIGH);
    }
  }
}

void onRelayChange() {
  if (relay) {
    digitalWrite(relayPin, HIGH);
  }
  else
    digitalWrite(relayPin, LOW);
}