#include <iostream>
#include <memory>
#include <list>
#include <wiringPi.h>
#include "ServoController.h"

#define  MIN_DISTANCE 25.0
#define  MAX_DISTANCE 75.0
#define  MID_DISTANCE 50.0
#define  MAX_ANGLE_SCOPE 180.0


ServoController::ServoController(std::shared_ptr<IServo> servo_ptr, std::shared_ptr<IDistanceSensor> disSen_ptr):servo(servo_ptr), distanceSensor(disSen_ptr){
    m_Unit = calculateUnit();
}

void ServoController::calculateAngle(){

    // std::list<int> distanceValues;

    // for(int i = 0; i < 50; i++){
    //     distanceValues.push_front(distanceSensor->calculateDistance());
    //     delay(5);
    // }
    // std::cout << distanceValues.size() << std::endl;
    // distanceValues.sort();

    // std::list<int>::iterator it = distanceValues.begin();
    // std::advance(it, distanceValues.size()/2);
    
    // int tempDistance = *it;

    // distanceValues.clear();

    int tempDistance = 0;

    for(int i = 0; i < 50; i++){
        tempDistance += distanceSensor->calculateDistance();
        delay(5);
    }

    tempDistance = tempDistance / 50;
    
    if(tempDistance<MIN_DISTANCE){
        m_Angle=-90;
    }
    else if(tempDistance>MAX_DISTANCE){
        m_Angle=90;
    }
    else if(tempDistance>=MIN_DISTANCE && tempDistance<MID_DISTANCE){
        m_Angle=(tempDistance-MID_DISTANCE)*m_Unit;
    }
    else if(tempDistance>MID_DISTANCE && tempDistance<=MAX_DISTANCE){
        m_Angle=(tempDistance-MID_DISTANCE)*m_Unit;
    }else{
        m_Angle=0;
    }
    std::cout<<"tempDistance: "<<tempDistance<<std::endl;
    std::cout<<"angle: "<<m_Angle<<std::endl;
}

int ServoController::calculateUnit(){
    return MAX_ANGLE_SCOPE/(MAX_DISTANCE-MIN_DISTANCE);
}

void ServoController::runServoToAngle(){
    servo->setAngle(m_Angle);
}
