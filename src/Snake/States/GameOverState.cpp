#include "../../../include/Snake/States/GameOverState.h"


namespace Snake {
GameOverState::GameOverState(StateManager& sm, Renderer& rd, Joystick& js)
    : State(sm, rd, js) {}
void GameOverState::handleInput() {
    if(m_Joystick.buttonPressed()) {
        m_StateManager.changeState(ArduinoEngine::States::Menu);
    }
}
void GameOverState::updateState() {}
void GameOverState::init() {
    m_StateManager.setDelay(m_Delay);
    m_Renderer.renderText("Game Over", Vector2f(20,110), 4, RED, TextOrientation::LANDSCAPE);
}
void GameOverState::draw() {}
}