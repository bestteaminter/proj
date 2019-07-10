#ifndef DEV_SERVOq
#define DEV_SERVOq

#include "IServo.h"

class Servo : public IServo
{
    private:
        int m_Pin;

        void init();
    public:
        Servo(int);
        void setAngle(int);
};
#endif