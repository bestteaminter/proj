
#ifndef DEV_DISTANCESEN
#define DEV_DISTANCESEN

#include "IDistanceSensor.h"

class DistanceSensor : public IDistanceSensor{
    private:
        int m_PinEcho;
        int m_PinTrigger;

        void init();
        void sendSignal();
        int checkDistance();
    public:
        DistanceSensor(int, int);
        int calculateDistance();
};


#endif