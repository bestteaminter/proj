#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include <memory>
#include "PwmController.h"

#define PIN 1
#define CLOCK 192
#define RANGE 2000

using namespace std;

int main(){
    wiringPiSetup();

    auto pwmController = make_unique<PwmController>(PIN, CLOCK, RANGE);

    printf("Frequency :%f \n",  pwmController->getFrequency());

    while(true){
        for(int i = 0; i <= 100; i++){
            pwmController->setProcentageValue(i);
            delay(100);
            cout << i << endl;
        }

        for(int i = 100; i >=0; i--){
            pwmController->setProcentageValue(i);
            delay(100);
            cout << i << endl;
        }
    }
}