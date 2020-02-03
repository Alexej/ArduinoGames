#include <Arduino.h>

#include "../include/ArduinoEngine/Renderer.h"
#include "../include/ArduinoEngine/Joystick.h"
#include "../include/ArduinoEngine/StateManager.h"


//Resolution 	320 x 240

ArduinoEngine::StateManager sm;
ArduinoEngine::Renderer rd;
ArduinoEngine::Joystick js;

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));

    rd.init();
    sm.init(rd, js);
}

void loop() {
    delay(sm.getDelay());
    sm.handleInput();
    sm.updateState();
    sm.draw();
}

