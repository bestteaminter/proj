#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <memory>
#include "DistanceSensor/DistanceSensor.h"
#include "servo/Servo.h"

class ServoController
{
private:
    double m_Unit;
    int m_Angle = 0;
    std::shared_ptr<IServo> servo;
    std::shared_ptr<IDistanceSensor> distanceSensor;

    int calculateUnit();
    int calculateDistance();

public:
    ServoController(std::shared_ptr<IServo>, std::shared_ptr<IDistanceSensor>);

    void runServoToAngle();
    void calculateAngle();

};

#endif