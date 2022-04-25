#include "dht_sensor.h"

using namespace karmek;

DhtSensor::DhtSensor(uint8_t pin, uint8_t type)
    : device(pin, type)
{
    device.begin();
    device.temperature().getSensor(sensor);
    device.humidity().getSensor(sensor);
}

double DhtSensor::temperature()
{
    device.temperature().getEvent(event);

    return event->temperature;
}

double DhtSensor::humidity()
{
    device.humidity().getEvent(event);

    return event->relative_humidity;
}

uint32_t DhtSensor::minDelayMs()
{
    return sensor->min_delay / 1000;
}