#include <iostream>
#include <memory>
#include <list>
#include <wiringPi.h>
#include "ServoController.h"

#define  MIN_DISTANCE 25.0
#define  MAX_DISTANCE 75.0
#define  MID_DISTANCE 50.0
#define  MAX_ANGLE_SCOPE 180.0

#define COUNT_OF_VALUES 20


ServoController::ServoController(std::shared_ptr<IServo> servo_ptr, std::shared_ptr<IDistanceSensor> disSen_ptr):servo(servo_ptr), distanceSensor(disSen_ptr){
    m_Unit = calculateUnit();
}

void ServoController::calculateAngle(){

    // std::list<int> distanceValues;
    // int lastDistance;

    // for(int i = 0; i < COUNT_OF_VALUES; i++){
    //     if(i == 0){
    //         lastDistance = distanceSensor->calculateDistance();
    //         distanceValues.push_front(lastDistance);
    //     }else{
    //         int temp = distanceSensor->calculateDistance();
    //         if((lastDistance + 2) > temp && (lastDistance - 2) < temp ){
    //             lastDistance = temp;
    //             distanceValues.push_front(lastDistance);
    //         }
    //     }
    //     delay(5);
    // }
    // std::cout << distanceValues.size() << std::endl;
    // distanceValues.sort();

    // std::list<int>::iterator it = distanceValues.begin();
    // std::advance(it, distanceValues.size()/2);
    
    // int tempDistance = *it;

    // distanceValues.clear();

    /////////////////////////////////////////////////
    // std::list<int> distanceValues;
    // int lastDistance;

    // for(int i = 0; i < COUNT_OF_VALUES; i++){
    //     if(i == 0){
    //         lastDistance = distanceSensor->calculateDistance();
    //     }else{
    //         distanceValues.push_front(distanceSensor->calculateDistance());
    //     }
    //     delay(2);
    // }
    // std::cout << distanceValues.size() << std::endl;
    // distanceValues.sort();

    // std::list<int>::iterator it = distanceValues.begin();
    // std::advance(it, distanceValues.size()/2);
    
    // int tempDistance = *it;

    // distanceValues.clear();

    ///////////////////////////////////////////////
    // int tempDistance = 0;

    // int distanceValues[COUNT_OF_VALUES];
    // int sum = 0;
    
    // for(int i = 0; i < COUNT_OF_VALUES; i++){
    //     distanceValues[i] = distanceSensor->calculateDistance();
    //     sum += distanceValues[i];
    //     delay(1);
    // }

    // double sr = sum/COUNT_OF_VALUES;

    // for(int i = 0; i < COUNT_OF_VALUES; i++){
    //     if((sr + 5) > distanceValues[i] && (sr - 5) < distanceValues[i]){
    //         tempDistance = distanceValues[i];
    //         break;
    //     }
    // }

    /////////////////////////////////////

    int tempDistance = distanceSensor->calculateDistance();

    for(int i = 0; i < COUNT_OF_VALUES; i++){
        delay(1);
        tempDistance = (3 * tempDistance + distanceSensor->calculateDistance()) / 4;
    }

    if(tempDistance == 0){
        return;
    }
    
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
