#ifndef H_OPTIONSSTATE
#define H_OPTIONSSTATE

#include "../../ArduinoEngine/State.h"
#include "../../ArduinoEngine/Joystick.h"
#include "../../ArduinoEngine/Renderer.h"
#include "../../ArduinoEngine/StateManager.h"

using ArduinoEngine::State;
using ArduinoEngine::Renderer;
using ArduinoEngine::StateManager;
using ArduinoEngine::Joystick;

namespace Snake{
    class OptionsState : public State{
        private:
            const int m_Delay = 50;
        public: 
            OptionsState(StateManager& sm, Renderer& rd, Joystick& js);
            void handleInput();
            void updateState(); 
            void init();
            void draw();
    };
}

#endif 