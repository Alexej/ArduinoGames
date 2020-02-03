#include "../../../include/Snake/States/OptionsState.h"


namespace Snake {
OptionsState::OptionsState(StateManager& sm, Renderer& rd, Joystick& js):
    State(sm, rd, js) {}
void OptionsState::handleInput() {
    if(m_Joystick.buttonPressed()) {
        m_StateManager.changeState(ArduinoEngine::States::Menu);
    }
}
void OptionsState::updateState() {}
void OptionsState::init() {
    m_StateManager.setDelay(m_Delay);
    m_Renderer.clear();
    m_Renderer.renderText("To Do", Vector2f(100,150), 4, RED, TextOrientation::LANDSCAPE);
}
void OptionsState::draw() {}
}