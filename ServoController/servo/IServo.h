#ifndef DEV_SERVO
#define DEV_SERVO

class IServo{
    public:
        virtual void setAngle(int) = 0;
};

#endif