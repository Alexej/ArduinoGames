#ifndef H_GAMESTATE
#define H_GAMESTATE

#include "../../ArduinoEngine/State.h"
#include "../../ArduinoEngine/Joystick.h"
#include "../../ArduinoEngine/Renderer.h"
#include "../../ArduinoEngine/StateManager.h"
#include "../../ArduinoEngine/PseudoVector.h"
#include "../SnakeBody.h"
#include "../Fruit.h"


using ArduinoEngine::State;
using ArduinoEngine::Renderer;
using ArduinoEngine::StateManager;
using ArduinoEngine::Joystick;
using ArduinoEngine::PseudoVector;

namespace Snake{
    struct FieldBounds{
        const Vector2f Start = Vector2f(10,10);
        const Vector2f End = Vector2f(220,230);
    }; 
    class GameState : public State {
        private:
            const int m_Delay = 100;
            FieldBounds m_Bounds;
            const int m_Size = 10;
            int m_Score;
            Fruit m_Fruit;
            SnakeBody m_Snake;
        public:
            GameState(StateManager& sm, Renderer& rd, Joystick& js);
            void handleInput();
            void updateState();
            void init();
            void gameOver();
            void draw();
    };
}
#endif