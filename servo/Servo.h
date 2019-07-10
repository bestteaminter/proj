#include "IServo.h"

class Servo : public IServo
{
    private:
        int m_Pin;

        void Init();
    public:
        Servo(int);
        void SetAngle(int);
};