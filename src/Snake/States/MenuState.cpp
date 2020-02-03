#include "../../../include/Snake/States/MenuState.h"


namespace Snake {
MenuState::MenuState(StateManager& sm, Renderer& rd, Joystick& js)
    : State(sm, rd, js)
{
    m_StateManager.setDelay(m_Delay);
    m_MenuArray[Menu::Play] = MenuElement(Menu::Play, "Play", Vector2f(130,120), 3, RED, TextOrientation::LANDSCAPE);
    m_MenuArray[Menu::Options] = MenuElement(Menu::Options, "Options", Vector2f(100,90), 3, WHITE, TextOrientation::LANDSCAPE);
    m_MenuArray[Menu::About] = MenuElement(Menu::About, "About", Vector2f(120,60), 3, WHITE, TextOrientation::LANDSCAPE);
    m_CurrentMenuChoice = &m_MenuArray[Menu::Play];
    m_CurrentGame = GameMenu::Snake;
}

void MenuState::handleInput() {
    if(m_Joystick.isUp()) {
        menuUp();
        while(m_Joystick.isUp()) {}
    }
    if(m_Joystick.isDown()) {
        menuDown();
        while(m_Joystick.isDown()) {}
    }    
    if(m_Joystick.isRight()) {
        gameMenuRight();
        while(m_Joystick.isRight()) {}
    }    
    if(m_Joystick.isLeft()) {
        gameMenuLeft();
        while(m_Joystick.isLeft()) {}
    }
    if(m_Joystick.buttonPressed()) {
        menuEnter();
    }
}
void MenuState::updateState() {}
void MenuState::init() {
    m_StateManager.setDelay(m_Delay);
    m_Renderer.clear();
}
void MenuState::menuDown() {
    switch(m_CurrentMenuChoice->m_Name) {
    case Menu::Play:
        m_CurrentMenuChoice->m_Color = WHITE;
        m_CurrentMenuChoice = &m_MenuArray[Menu::Options];
        m_CurrentMenuChoice->m_Color = RED;
        break;
    case Menu::Options:
        m_CurrentMenuChoice->m_Color = WHITE;
        m_CurrentMenuChoice = &m_MenuArray[Menu::About];
        m_CurrentMenuChoice->m_Color = RED;
        break;
    case Menu::About:
        m_CurrentMenuChoice->m_Color = WHITE;
        m_CurrentMenuChoice = &m_MenuArray[Menu::Play];
        m_CurrentMenuChoice->m_Color = RED;
        break;
    }
}
void MenuState::menuUp() {
    switch(m_CurrentMenuChoice->m_Name) {
    case Menu::Play:
        m_CurrentMenuChoice->m_Color = WHITE;
        m_CurrentMenuChoice = &m_MenuArray[Menu::About];
        m_CurrentMenuChoice->m_Color = RED;
        break;
    case Menu::Options:
        m_CurrentMenuChoice->m_Color = WHITE;
        m_CurrentMenuChoice = &m_MenuArray[Menu::Play];
        m_CurrentMenuChoice->m_Color = RED;
        break;
    case Menu::About:
        m_CurrentMenuChoice->m_Color = WHITE;
        m_CurrentMenuChoice = &m_MenuArray[Menu::Options];
        m_CurrentMenuChoice->m_Color = RED;
        break;
    }
}
void MenuState::menuEnter() {
    switch(m_CurrentMenuChoice->m_Name) {
    case Menu::About:
        m_StateManager.changeState(ArduinoEngine::States::About);
        break;
    case Menu::Play:
        switch(m_CurrentGame){
            case GameMenu::Snake:
                m_StateManager.changeState(ArduinoEngine::States::Game);
                break;
            case GameMenu::Pong:
                m_StateManager.changeState(ArduinoEngine::States::Pong);
                break;
            case GameMenu::Tic:
                m_StateManager.changeState(ArduinoEngine::States::Tic);
                break;
        }
        break;
    case Menu::Options:
        m_StateManager.changeState(ArduinoEngine::States::Options);
        break;
    }
}


void MenuState::gameMenuRight(){
    switch(m_CurrentGame){
        case GameMenu::Snake:
            m_Renderer.renderText("Snake", Vector2f(90,160), 5, BLACK, TextOrientation::LANDSCAPE);
            m_CurrentGame = GameMenu::Tic;
            break;
        case GameMenu::Tic:
            m_Renderer.renderText("Crosses", Vector2f(60,160), 5, BLACK, TextOrientation::LANDSCAPE);
            m_CurrentGame = GameMenu::Pong;
            break;
        case GameMenu::Pong:
            m_Renderer.renderText("Pong", Vector2f(105,160), 5, BLACK, TextOrientation::LANDSCAPE);
            m_CurrentGame = GameMenu::Snake;
            break;
    }
}

void MenuState::gameMenuLeft(){
    switch(m_CurrentGame){
        case GameMenu::Snake:
            m_Renderer.renderText("Snake", Vector2f(90,160), 5, BLACK, TextOrientation::LANDSCAPE);
            m_CurrentGame = GameMenu::Pong;
            break;
        case GameMenu::Pong:
            m_Renderer.renderText("Pong", Vector2f(105,160), 5, BLACK, TextOrientation::LANDSCAPE);
            m_CurrentGame = GameMenu::Tic;
            break;
        case GameMenu::Tic:
            m_Renderer.renderText("Crosses", Vector2f(60,160), 5, BLACK, TextOrientation::LANDSCAPE);
            m_CurrentGame = GameMenu::Snake;
            break;
    }
}

void MenuState::draw() {
    switch(m_CurrentGame){
        case GameMenu::Snake:
            m_Renderer.renderText("Snake", Vector2f(90,160), 5, YELLOW, TextOrientation::LANDSCAPE);
            break;
        case GameMenu::Pong:
            m_Renderer.renderText("Pong", Vector2f(105,160), 5, GREEN, TextOrientation::LANDSCAPE);
            break;
        case GameMenu::Tic:
            m_Renderer.renderText("Crosses", Vector2f(60,160), 5, BRIGHT_RED, TextOrientation::LANDSCAPE);
            break;
    }
    for(MenuElement e : m_MenuArray) {
        m_Renderer.renderText(e.m_String, e.m_Pos, e.m_Size, e.m_Color, e.m_Te);
    }
}
}