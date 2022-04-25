#include <Arduino.h>

constexpr int baudRate{9600};

void setup()
{
    Serial.begin(baudRate);
    Serial.println("Hello, world!");
}

void loop()
{
    Serial.println("123");
    delay(1000UL);
}