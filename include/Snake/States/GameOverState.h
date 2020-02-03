#ifndef H_GAMEOVERSTATE
#define H_GAMEOVERSTATE

#include "../../ArduinoEngine/State.h" 
#include "../../ArduinoEngine/Joystick.h"
#include "../../ArduinoEngine/Renderer.h"
#include "../../ArduinoEngine/StateManager.h"

using ArduinoEngine::State;
using ArduinoEngine::Renderer;
using ArduinoEngine::StateManager;
using ArduinoEngine::Joystick;

namespace Snake{  
    class GameOverState : public State {
        private:
            const int m_Delay = 50;
        public:
            GameOverState(StateManager& sm, Renderer& rd, Joystick& js);
            void handleInput();
            void updateState(); 
            void init();
            void draw();
    };
}

#endif