#ifndef H_STATEMANAGER
#define H_STATEMANAGER

#include "State.h"
#include "../Snake/States/MenuState.h"
#include "../Snake/States/GameState.h"
#include "../Snake/States/AboutState.h"
#include "../Snake/States/PauseState.h"
#include "../Snake/States/GameOverState.h"
#include "../Snake/States/OptionsState.h"

#include "../Pong/States/PongState.h"
#include "../Pong/States/PongPauseState.h"
#include "../Pong/States/PongGameOverState.h"

#include "../Tic/States/TikState.h"

namespace ArduinoEngine{
    class StateManager
    {
    private:
        bool m_GameIsRunning;
        int m_Delay;
        State* m_StateArray[States::LENGTH];
        States m_CurrentState;
    public:
        void changeState(States state, bool init = true);
        void init(Renderer& rd, Joystick& js);
        void updateState();
        void handleInput();
        void draw();
        const int getDelay() const {return m_Delay;}
        void setDelay(int delay) {m_Delay = delay;}
        bool isRunning() const { return m_GameIsRunning;}
    };
}
#endif