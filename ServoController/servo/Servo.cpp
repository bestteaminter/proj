#include <wiringPi.h>
#include "Servo.h"

Servo::Servo(int pin)
{
    m_Pin = pin;

    init();
}

void Servo::init()
{
    pinMode(m_Pin, PWM_OUTPUT);

    pwmSetMode(PWM_MODE_MS);

    pwmSetClock(192);
    pwmSetRange(2000);
}

void Servo::setAngle(int angle)
{
    int value = (angle + 90) * 1.11;

    pwmWrite(m_Pin, 51 + value);
}