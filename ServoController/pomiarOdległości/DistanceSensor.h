
#ifndef DEV_DISTANCESEN
#define DEV_DISTANCESEN

#include "IDistanceSensor.h"

class DistanceSensor : public IDistanceSensor{
    private:
        int m_PinEcho;
        int m_PinTrigger;

        void Init();
        void SendSignal();
        int CheckDistance();
    public:
        DistanceSensor(int, int);
        int CalculateDistance();
};


#endif