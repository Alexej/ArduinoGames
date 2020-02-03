#include "../../../include/Snake/States/GameState.h"

namespace Snake {
GameState::GameState(StateManager& sm, Renderer& rd, Joystick& js)
    : State(sm, rd, js)
{
}

void GameState::handleInput() {
    if(m_Joystick.isUp() && m_Snake.getDirection() != Direction::Down)
    {
        m_Snake.setDirectionUp();
    }
    else if(m_Joystick.isDown() && m_Snake.getDirection() != Direction::Up)
    {
        m_Snake.setDirectionDown();
    }
    else if(m_Joystick.isLeft() && m_Snake.getDirection() != Direction::Right)
    {
        m_Snake.setDirectionLeft();
    }
    else if(m_Joystick.isRight() && m_Snake.getDirection() != Direction::Left)
    {
        m_Snake.setDirectionRight();
    }
    else if(m_Joystick.buttonPressed()) {
        m_StateManager.changeState(ArduinoEngine::States::Pause);
    }
}
void GameState::updateState() {
    m_Snake.update();
    if(m_Snake.checkCollision(m_Snake.getHeadPosition(), Collision::Body) && m_Snake.length() > 2) {
        gameOver();
    }
    if(m_Snake.getHeadPosition() == m_Fruit.getPosition())
    {
        m_Renderer.renderNumber(m_Score, Vector2f(250, 180), 2, BLACK, LANDSCAPE);
        m_Score++;
        m_Renderer.renderRectangle(m_Fruit.getPosition(), Vector2f(m_Size,m_Size),BLACK);
        m_Snake.push(m_Fruit.getPosition());
        do {
            m_Fruit.setFruitPosition();
        } while(m_Snake.checkCollision(m_Fruit.getPosition(), Collision::Frucht));
        m_Renderer.renderNumber(m_Score, Vector2f(250, 180), 2, WHITE, LANDSCAPE);
    }
    if(m_Snake.getHeadPositionReference().x > m_Bounds.End.x ||
            m_Snake.getHeadPositionReference().x < m_Bounds.Start.x ||
            m_Snake.getHeadPositionReference().y > m_Bounds.End.y ||
            m_Snake.getHeadPositionReference().y < m_Bounds.Start.y)
    {
        gameOver();
    }
}
void GameState::init() {
    m_Score = 0;
    m_StateManager.setDelay(m_Delay);
    m_Renderer.clear();
    m_Snake.init();
    m_Renderer.renderBorder(Vector2f(4,4), Vector2f(231,241),BLUE);
    m_Renderer.renderText("Score", Vector2f(250, 205), 2, WHITE, LANDSCAPE);

    m_Renderer.renderBorder(Vector2f(40, 260), Vector2f(50,50), BLUE);
    m_Renderer.renderText("S",Vector2f(270, 47), 4, BRIGHT_RED, TextOrientation::LANDSCAPE);

    m_Renderer.renderNumber(m_Score, Vector2f(250, 180), 2, WHITE, LANDSCAPE);
}
void GameState::draw() {
    m_Renderer.renderRectangle(m_Snake.getSnakeElement(m_Snake.length()-1), Vector2f(m_Size,m_Size),BLACK);
    for(int i = 0; i < m_Snake.length()-1; i++) {
        m_Renderer.renderRectangle(m_Snake.getSnakeElement(i), Vector2f(m_Size,m_Size),GREEN);
        m_Renderer.renderBorder(m_Snake.getSnakeElement(i), Vector2f(m_Size,m_Size),BLACK);

    }
    m_Renderer.renderRectangle(m_Fruit.getPosition(), Vector2f(m_Size,m_Size),RED);
    m_Renderer.renderBorder(m_Fruit.getPosition(), Vector2f(m_Size,m_Size),BLACK);
}

void GameState::gameOver() {
    m_Renderer.renderText("S",Vector2f(270, 47), 4, BLACK, TextOrientation::LANDSCAPE);
    m_Renderer.renderText("X",Vector2f(270, 47), 4, YELLOW, TextOrientation::LANDSCAPE);
    m_StateManager.changeState(ArduinoEngine::States::GameOver);
}
}