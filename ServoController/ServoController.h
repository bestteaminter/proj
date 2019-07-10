#include <memory>
#include "pomiarOdległosci/DistanceSensor.h"
#include "servo/Servo.h"

class ServoController
{
private:
    int angle = 0;
    std::shared_ptr<IServo> servo;
    std::shared_ptr<IDistanceSensor> distanceSensor;

public:
    ServoController();
    ServoController(std::shared_ptr<IServo>, std::shared_ptr<IDistanceSensor>);

    ~ServoController();
    void calculateAngle();
    void runServoToAngle();

};
