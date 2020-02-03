#include "../../../include/Snake/States/PauseState.h"

namespace Snake {
PauseState::PauseState(StateManager& sm, Renderer& rd, Joystick& js)
    :State(sm, rd, js) {}
void PauseState::handleInput() {
    if(m_Joystick.buttonPressed()) {
        m_Renderer.renderText("P",Vector2f(270, 47), 4, BLACK, TextOrientation::LANDSCAPE);
        m_Renderer.renderText("S",Vector2f(270, 47), 4, BRIGHT_RED, TextOrientation::LANDSCAPE);
        m_StateManager.changeState(ArduinoEngine::States::Game, false);
    }
}
void PauseState::updateState() {}
void PauseState::init() {
    m_Renderer.renderText("S",Vector2f(270, 47), 4, BLACK, TextOrientation::LANDSCAPE);
    m_Renderer.renderText("P",Vector2f(270, 47), 4, WHITE, TextOrientation::LANDSCAPE);

}
void PauseState::draw() {}
}