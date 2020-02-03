#include "../../include/ArduinoEngine/Joystick.h"

namespace ArduinoEngine {
Joystick::Joystick()
{
    m_State = false;
    pinMode(BUTTON, INPUT_PULLUP);
}

bool Joystick::isLeft() {
    int x = analogRead(JOYX);
    return x < 256 ? true : false;

}
bool Joystick::isRight() {
    int x = analogRead(JOYX);
    return x > 768 ? true : false;

}
bool Joystick::isUp() {
    int y = analogRead(JOYY);
    return y < 256 ? true : false;

}
bool Joystick::isDown() {
    int y = analogRead(JOYY);
    return y > 768 ? true : false;
}

bool Joystick::buttonPressed() {
    if(digitalRead(BUTTON)==LOW && !m_State) {
        m_State = true;
        return true;
    }
    else {
        m_State = false;
        while(digitalRead(BUTTON)==LOW) {}
        return false;
    }
}
}
