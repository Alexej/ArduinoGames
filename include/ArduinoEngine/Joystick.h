#ifndef H_JOYSTICK
#define H_JOYSTICK


#define JOYY A8
#define JOYX A9
#define BUTTON 26

#include "Arduino.h"

namespace ArduinoEngine{
    class Joystick
    {
    private:
    bool m_State;
    public:
        Joystick();
        bool isRight();
        bool isLeft();
        bool isUp();
        bool isDown();
        bool buttonPressed();
    };
}

#endif