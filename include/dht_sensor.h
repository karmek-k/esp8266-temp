#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

namespace karmek
{
    class DhtSensor
    {
    private:
        DHT_Unified device;
        sensor_t *sensor;
        sensors_event_t *event;

    public:
        DhtSensor(uint8_t pin, uint8_t type);

        double temperature();
        double humidity();

        uint32_t minDelayMs();
    };
}

#endif