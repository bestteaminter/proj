#include <iostream>
#include <wiringPi.h>
#include "DistanceSensor.h"

using namespace std;

#define PIN_TRIGGER 7
#define PIN_ECHO 0

int main()
{
    wiringPiSetup();

    DistanceSensor* ds = new DistanceSensor(PIN_ECHO, PIN_TRIGGER);
    cout << ds->calculateDistance() << " cm" << endl;
    delete ds;

    return 0;
}