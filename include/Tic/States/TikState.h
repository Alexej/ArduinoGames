#ifndef H_TIKSTATE
#define H_TIKSTATE

#include "../../../lib/TFT_Touch_Shield_V2-master/SeeedTouchScreen.h"

#include "../../ArduinoEngine/State.h"
#include "../../ArduinoEngine/Joystick.h"
#include "../../ArduinoEngine/Renderer.h"
#include "../../ArduinoEngine/StateManager.h"

using ArduinoEngine::State;
using ArduinoEngine::Renderer;
using ArduinoEngine::StateManager;
using ArduinoEngine::Joystick;


#define TS_MINX 116*2
#define TS_MAXX 890*2
#define TS_MINY 83*2
#define TS_MAXY 913*2

namespace Tik{
    class TikState : public State{
        private:
            char* m_Field[9] = {0};
            Point m_Point;
            bool m_isRunning;
            TouchScreen m_TS = TouchScreen(XP, YP, XM, YM);
            const int m_Delay = 50;
            bool m_ShieldIsPressed = false;
        public:
            TikState(StateManager& sm, Renderer& rd, Joystick& js);
            void handleInput();
            void updateState(); 
            void init();
            void draw();

            bool checkIfCellFree(int i);
            bool checkWin(char** f, char* p);
            void drawXO(char* c, int i, int COLOR = WHITE);

            void AI();
            int minimax(char** m, int depth, bool isMax);
            int findBestMove();
            bool movesLeft(char** f);
            int evaluate(char** f);
            void drawCurrentState(char** m);
    };
}

#endif 