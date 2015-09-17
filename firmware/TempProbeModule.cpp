#include "TemperatureProbe.h"
#include "Modulo.h"

TemperatureProbeModulo::TemperatureProbeModulo() :
    ModuloBase("co.modulo.tempprobe")
{
}

TemperatureProbeModulo::TemperatureProbeModulo(uint16_t deviceID) :
    ModuloBase("co.modulo.tempprobe", deviceID)
{
}

#define FUNCTION_GET_TEMPERATURE 0

const float TemperatureProbeModulo::InvalidTemperature = -1000;

float TemperatureProbeModulo::getTemperatureC() {

    uint8_t receiveData[2] = {0,0};

    if (!_transfer(FUNCTION_GET_TEMPERATURE, 0, 0,
                        receiveData, 2)) {
        return 0;
        // Handle error?
    }
    int16_t value = receiveData[0] | (receiveData[1] << 8);
    return value/10.0;
}

float TemperatureProbeModulo::getTemperatureF() {
    return getTemperatureC()*1.8 + 32;
}
