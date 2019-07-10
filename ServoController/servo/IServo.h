#ifndef DEV_SERVO
#define DEV_SERVO

class IServo{
    public:
        virtual void SetAngle(int) = 0;
};

#endif