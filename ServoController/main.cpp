#include <iostream>
#include "ServoController.h"
#include "servo/Servo.h"
#include "pomiarOdległości/DistanceSensor.h"

#define PIN_TRIGGER 7
#define PIN_ECHO 0

int main(){
    std::shared_ptr<IServo> servo_ptr= std::make_shared<Servo>(1);
    std::shared_ptr<IDistanceSensor> disSen_ptr=std::make_shared<DistanceSensor>(PIN_ECHO, PIN_TRIGGER);

    ServoController* servoController = new ServoController(servo_ptr, disSen_ptr);
    servoController->calculateAngle();

    std::cout<<"Start"<<std::endl;
}