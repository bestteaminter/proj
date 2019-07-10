#include <iostream>
#include <wiringPi.h>
#include "ServoController.h"
#include "servo/Servo.h"
#include "pomiarOdległosci/DistanceSensor.h"

#define PIN_TRIGGER 7
#define PIN_ECHO 0
#define PIN_SERVO 1

int main(){

    wiringPiSetup();
    
    std::shared_ptr<IServo> servo_ptr= std::make_shared<Servo>(PIN_SERVO);
    std::shared_ptr<IDistanceSensor> disSen_ptr=std::make_shared<DistanceSensor>(PIN_ECHO, PIN_TRIGGER);

    ServoController* servoController = new ServoController(servo_ptr, disSen_ptr);

    while (true)
    {
        servoController->calculateAngle();
        servoController->runServoToAngle();
        delay(100);
    }
    

    std::cout<<"Start"<<std::endl;
}