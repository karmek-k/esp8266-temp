#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

namespace karmek
{
    enum class DhtSensorType
    {
        DHT11 = 11,
        DHT12 = 12,
        DHT21 = 21,
        DHT22 = 22,
    };

    class DhtSensor
    {
    private:
        DHT_Unified device;
        sensor_t *sensor;
        sensors_event_t *event;

    public:
        DhtSensor(uint8_t pin, DhtSensorType type);

        double temperature();
        double humidity();
    };
}

#endif