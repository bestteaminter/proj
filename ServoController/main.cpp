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
    
    auto servo_ptr= std::make_shared<Servo>(PIN_SERVO);
    auto disSen_ptr=std::make_shared<DistanceSensor>(PIN_ECHO, PIN_TRIGGER);

    //auto servoController=std::make_unique<ServoController>(servo_ptr, disSen_ptr);
    ServoController* servoController = new ServoController(servo_ptr, disSen_ptr);

    while (true)
    {
        servoController->calculateAngle();
        servoController->runServoToAngle();
        delay(100);
    }
    

    std::cout<<"Start"<<std::endl;
}