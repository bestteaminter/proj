#include <iostream>
#include <wiringPi.h>
#include "DistanceSensor.h"

using namespace std;

void DistanceSensor::Init()
{
    pinMode(m_PinTrigger, OUTPUT);
    pinMode(m_PinEcho, INPUT);
            
    digitalWrite(m_PinTrigger, LOW);
    cout << "Waiting for sensor to settle" << endl;
    delay(2000);
}

void DistanceSensor::SendSignal()
{
    digitalWrite(m_PinTrigger, HIGH);
    delay(0.1);
    digitalWrite(m_PinTrigger, LOW);
}

int DistanceSensor::CheckDistance()
{
    cout << "Calculate distance" << endl;
    
    while(digitalRead(m_PinEcho) == LOW){}
    long start = micros();

    while(digitalRead(m_PinEcho) == HIGH){}
    long stop = micros();

    int distance = (stop - start)/58;

    return distance;
}

DistanceSensor::DistanceSensor(int pinEcho, int pinTrigger)
{
    m_PinEcho = pinEcho;
    m_PinTrigger = pinTrigger;

    Init();
}

int DistanceSensor::CalculateDistance(){
    SendSignal();
    return CheckDistance();
}