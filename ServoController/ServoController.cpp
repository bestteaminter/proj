#include <iostream>
#include <memory>
#include "ServoController.h"

#define  MIN 25.0
#define  MAX 75.0
#define  MID 50.0
#define  SCOPE 180.0

ServoController::ServoController(std::shared_ptr<IServo> servo_ptr, std::shared_ptr<IDistanceSensor> disSen_ptr){
    servo=servo_ptr;
    distanceSensor=disSen_ptr;
}

void ServoController::calculateAngle(){
    int tempDistance=distanceSensor->calculateDistance();
    double unit=SCOPE/(MAX-MIN);
    if(tempDistance<MIN){
        angle=-90;
    }
    else if(tempDistance>MAX){
        angle=90;
    }
    else if(tempDistance>=MIN && tempDistance<MID){
        angle=(tempDistance-MID)*unit;
    }
    else if(tempDistance>MID && tempDistance<=MAX){
        angle=(tempDistance-MID)*unit;
    }else{
        angle=0;
    }
    std::cout<<"tempDistance: "<<tempDistance<<std::endl;
    std::cout<<"angle: "<<angle<<std::endl;

}

void ServoController::runServoToAngle(){
    servo->setAngle(angle);
}
