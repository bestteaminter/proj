#ifndef I_SERVO_H
#define I_SERVO_H

class IServo{
    public:
        virtual void setAngle(int) = 0;
};

#endif