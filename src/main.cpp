#include <Arduino.h>

#include "dht_sensor.h"

constexpr int baudRate{9600};

constexpr int dhtPowerPin{D7};
constexpr int dhtOutPin{D8};

karmek::DhtSensor sensor{dhtOutPin, DHT11};

void setup()
{
    Serial.begin(baudRate);

    pinMode(dhtPowerPin, OUTPUT);
    digitalWrite(dhtPowerPin, HIGH);
}

void loop()
{
    Serial.println(sensor.temperature());
    delay(1000UL);
}