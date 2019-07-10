#include <memory>
#include "pomiarOdległosci/DistanceSensor.h"
#include "servo/Servo.h"

class ServoController
{
private:
    double m_Unit;
    int m_Angle = 0;
    std::shared_ptr<IServo> servo;
    std::shared_ptr<IDistanceSensor> distanceSensor;
    int calculateUnit();

public:
    ServoController();
    ServoController(std::shared_ptr<IServo>, std::shared_ptr<IDistanceSensor>);

    ~ServoController();
    void runServoToAngle();
    void calculateAngle();

};
