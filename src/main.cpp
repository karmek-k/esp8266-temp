#include <sstream>
#include <iomanip>

#include <Arduino.h>

#include "dht_sensor.h"
#include "screen.h"

constexpr int baudRate{9600};

constexpr int dhtPowerPin{D7};
constexpr int dhtOutPin{D8};

constexpr int screenClockPin{D1};
constexpr int screenDataPin{D2};

std::stringstream ss;
karmek::DhtSensor sensor{dhtOutPin, DHT11};
karmek::Screen screen{screenClockPin, screenDataPin};

void setup()
{
    Serial.begin(baudRate);

    pinMode(dhtPowerPin, OUTPUT);
    digitalWrite(dhtPowerPin, HIGH);
}

void loop()
{
    delay(sensor.minDelayMs());

    std::stringstream().swap(ss);
    ss << std::setprecision(2) << sensor.humidity() << "% ";
    ss << std::setprecision(2) << sensor.temperature() << "C";

    screen.print(0, 64 - 24, ss.str().c_str());
}