
#ifndef DEV_DISTANCE
#define DEV_DISTANCE


class IDistanceSensor
{
    public:
        virtual int calculateDistance() = 0;
};

#endif
