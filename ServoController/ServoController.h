#include <memory>
#include "pomiarOdległości/DistanceSensor.h"
#include "servo/Servo.h"

class ServoController
{
private:
    int angle;
    std::shared_ptr<IServo> servo;
    std::shared_ptr<IDistanceSensor> distanceSensor;
    //IServo* servo;
    //IDistanceSensor* distanceSensor;

public:
    ServoController();
    ServoController(std::shared_ptr<IServo>, std::shared_ptr<IDistanceSensor>);
    //ServoController(IServo*, IDistanceSensor*);

    ~ServoController();
    void calculateAngle();

};
