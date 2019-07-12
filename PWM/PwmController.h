#ifndef PWM_CONTROLLER_H
#define PWM_CONTROLLER_H

class PwmController{
    private:
        int m_Pin;
        int m_Clock;
        int m_Range;

        void init();

    public:
        PwmController(int pin, int clock, int range);
        void setProcentageValue(int procentageValue);
        double getFrequency();
};

#endif