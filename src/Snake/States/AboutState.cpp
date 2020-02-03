#include "../../../include/Snake/States/AboutState.h"

namespace Snake {
AboutState::AboutState(StateManager& sm, Renderer& rd, Joystick& js)
    : State(sm, rd, js) {}

void AboutState::handleInput() {
    if(m_Joystick.buttonPressed()) {
        m_StateManager.changeState(ArduinoEngine::States::Menu);
    }
}

void AboutState::updateState() {}

void AboutState::init() {
    m_StateManager.setDelay(m_Delay);
    m_Renderer.clear();
    m_Renderer.renderText("About", Vector2f(115,200), 3, YELLOW, TextOrientation::LANDSCAPE);
}
void AboutState::draw() {}
}
