
#ifndef DEV_DISTANCE
#define DEV_DISTANCE


class IDistanceSensor
{
    public:
        virtual int CalculateDistance() = 0;
};

#endif
