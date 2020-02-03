#ifndef H_MENUSTATE
#define H_MENUSTATE

#include "../../ArduinoEngine/State.h"
#include "../../ArduinoEngine/Joystick.h"
#include "../../ArduinoEngine/Renderer.h"
#include "../../ArduinoEngine/StateManager.h"

using ArduinoEngine::State;
using ArduinoEngine::Renderer;
using ArduinoEngine::StateManager;
using ArduinoEngine::Joystick;

namespace Snake{
    enum Menu {Play = 0, Options = 1, About = 2, LENGTH = 3};
    enum GameMenu {Tic = 0, Snake = 1, Pong = 2};
    struct MenuElement{
        Menu m_Name;
        char* m_String;
        Vector2f m_Pos;
        int m_Size, m_Color;
        TextOrientation m_Te;
        MenuElement(){}
        MenuElement(Menu name, char* s, Vector2f v, int size, int c, TextOrientation t)
         :m_Name(name), m_String(s), m_Pos(v), m_Size(size), m_Color(c), m_Te(t) {}
    };
    
    class MenuState : public State
    {        
    private:
        const int m_Delay = 50;
        MenuElement m_MenuArray[Menu::LENGTH];
        MenuElement* m_CurrentMenuChoice; 
        GameMenu m_CurrentGame;
    public:
        MenuState(StateManager& sm, Renderer& rd, Joystick& js);
        void handleInput();
        void gameMenuLeft();
        void gameMenuRight();
        void updateState();
        void menuUp();
        void init();
        void menuDown();
        void menuEnter();
        void draw();
    };
}
#endif