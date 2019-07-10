#include <iostream>
#include <wiringPi.h>
#include "Servo.h"

using namespace std;

#define PIN 1

int main()
{

    wiringPiSetup();

    Servo* servo = new Servo(PIN);
    servo->SetAngle(-90);
    delay(1000);
    servo->SetAngle(-25);
    delay(1000);
    servo->SetAngle(90);
    delay(1000);
    servo->SetAngle(25);
    delay(1000);
    servo->SetAngle(0);
    
    // cout << "start" << endl;
    // wiringPiSetup();

    // pinMode(PIN, PWM_OUTPUT);

    // pwmSetMode(PWM_MODE_MS);

    // pwmSetClock(192);
    // pwmSetRange(2000);
    // delay(1000);

    // int i = 250;
    // pwmWrite(PIN, i);
    // delay(1000);

    // while(i >= 55){
    //     cout << i << endl;
    //     pwmWrite(PIN, i);
    //     i--;
        
    // }

    // pwmWrite(PIN, 150);

    // pwmWrite(PIN, 150);
    // delay(1000);
    // pwmWrite(PIN, 250);
    // delay(1000);
    // pwmWrite(PIN, 200);
    // delay(1000);
    // pwmWrite(PIN, 100);
    // delay(1000);
    // pwmWrite(PIN, 60);
    // delay(1000);
    // pwmWrite(PIN, 150);

    //pwmWrite(PIN, -50);
    // delay(1000);
    // pwmWrite(PIN, 0);
    // delay(1000);
    // pwmWrite(PIN, 50);
    // delay(1000);
    // pwmWrite(PIN, 100);
    // delay(1000);
    // pwmWrite(PIN, 150);
    // delay(1000);
    // pwmWrite(PIN, 200);
    // delay(1000);
    // pwmWrite(PIN, 250);
    // delay(1000);
    // pwmWrite(PIN, 300);
    // delay(1000);

    return 0;
}