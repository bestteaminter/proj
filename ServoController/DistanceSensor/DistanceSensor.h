
#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "IDistanceSensor.h"

class DistanceSensor : public IDistanceSensor{
    private:
        int m_PinEcho;
        int m_PinTrigger;

        void init();
        void sendSignal();
        int checkDistance();
    public:
        DistanceSensor(int pinEcho, int pinTrigger);
        int calculateDistance();
};


#endif