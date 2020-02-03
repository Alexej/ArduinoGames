#include "../../include/ArduinoEngine/StateManager.h"

namespace ArduinoEngine {
void StateManager::changeState(States state, bool init = true) {
    m_CurrentState = state;
    if(init) {
        m_StateArray[m_CurrentState]->init();
    }
}
void StateManager::init(Renderer& rd, Joystick& js) {
    m_CurrentState = States::Menu;
    m_StateArray[States::Menu] = new Snake::MenuState(*this,rd, js);
    m_StateArray[States::Game] = new Snake::GameState(*this,rd, js);
    m_StateArray[States::Options] = new Snake::OptionsState(*this,rd, js);
    m_StateArray[States::About] = new Snake::AboutState(*this,rd, js);
    m_StateArray[States::Pause] = new Snake::PauseState(*this,rd, js);
    m_StateArray[States::GameOver] = new Snake::GameOverState(*this,rd, js);

    m_StateArray[States::Pong] = new Pong::PongState(*this,rd, js);
    m_StateArray[States::PongPause] = new Pong::PongPauseState(*this,rd, js);
    m_StateArray[States::PongGameOver] = new Pong::PongGameOverState(*this,rd, js);

    m_StateArray[States::Tic] = new Tik::TikState(*this,rd, js);

    m_GameIsRunning = true;
}
void StateManager::updateState() {
    m_StateArray[m_CurrentState]->updateState();
}
void StateManager::handleInput() {
    m_StateArray[m_CurrentState]->handleInput();
}
void StateManager::draw() {
    m_StateArray[m_CurrentState]->draw();
}
}