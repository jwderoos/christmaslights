class ModeInterface {
    protected:
        int pinOne, pinTwo;
    public:
        ModeInterface(int pinOne, int pinTwo) {
            this->pinOne = pinOne;
            this->pinTwo = pinTwo;
        }
        virtual void reset() = 0;
        virtual void step() = 0;
};