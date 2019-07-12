#include <wiringPi.h>
#include "Servo.h"

constexpr int MIN= 55;
constexpr int MAX= 250;
constexpr int MAX_ANGLE= 180;
constexpr int MID_ANGLE= 90;

Servo::Servo(int pin):m_Pin(pin)
{
    init();
}

void Servo::init()
{
    pinMode(m_Pin, PWM_OUTPUT);

    pwmSetMode(PWM_MODE_MS);

    pwmSetClock(192);
    pwmSetRange(2000);

    m_Unit = (MAX - MIN) / MAX_ANGLE;
}

void Servo::setAngle(int angle)
{
    int value = (angle + MID_ANGLE) * m_Unit;

    pwmWrite(m_Pin, MIN + value);
}
