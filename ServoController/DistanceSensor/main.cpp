#include <iostream>
#include <wiringPi.h>
#include <memory>
#include "DistanceSensor.h"

using namespace std;

#define PIN_TRIGGER 7
#define PIN_ECHO 0

int main()
{
    wiringPiSetup();

    auto ds = make_unique<DistanceSensor>(PIN_ECHO, PIN_TRIGGER);
    cout << ds->calculateDistance() << " cm" << endl;

    return 0;
}