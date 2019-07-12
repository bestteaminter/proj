#include "PwmController.h"
#include <iostream>
#include <wiringPi.h>

constexpr int  DEFAULT_FREQUENCY= 19200000; //Hz

using namespace std;

PwmController::PwmController(int pin, int clock, int range): m_Pin(pin), m_Clock(clock), m_Range(range){
    init();
}

void PwmController::init(){
    pinMode(m_Pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);

    pwmSetClock(m_Clock);
    pwmSetRange(m_Range);
}

void PwmController::setProcentageValue(int procentageValue){
    int value = (procentageValue * m_Range) / 100;
    pwmWrite(m_Pin, value);
}

double PwmController::getFrequency(){
    return DEFAULT_FREQUENCY / (m_Clock * m_Range);
}
