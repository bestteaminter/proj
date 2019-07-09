
class DistanceSensor{
    private:
        int m_PinEcho;
        int m_PinTrigger;

        void Init();
        void SendSignal();
        int CheckDistance();
    public:
        DistanceSensor(int, int);
        int CalculateDistance();
};