#ifndef H_STATE
#define H_STATE


namespace ArduinoEngine{
    class StateManager;
    class Renderer;
    class Joystick;
    enum States {Intro = 0, Menu = 1, Game = 2, Options = 3, About = 4, 
    Pause = 5, GameOver = 6, PongGameOver = 7, Pong = 8, PongPause = 9, Tic, TicWin = 10, TicLoose = 11, LENGTH = 12};
    class State
    {
    protected:
        StateManager& m_StateManager;
        Renderer& m_Renderer;
        Joystick& m_Joystick;
    public:
        State(StateManager& sm, Renderer& rd, Joystick& js)
         : m_StateManager(sm), m_Renderer(rd), m_Joystick(js) {}
        virtual void handleInput() = 0;
        virtual void init() = 0;
        virtual void updateState() = 0;
        virtual void draw() = 0;
    };
}
#endif