#include "../../include/Snake/SnakeBody.h"

namespace Snake {
const Vector2f SnakeBody::getHeadPosition() const {
    return m_SnakeBody[HEADPOSITION];
}
void SnakeBody::setDirectionUp() {
    m_Dir = Direction::Up;
}
void SnakeBody::setDirectionDown() {
    m_Dir = Direction::Down;
}
void SnakeBody::setDirectionRight() {
    m_Dir = Direction::Right;
}
void SnakeBody::setDirectionLeft() {
    m_Dir = Direction::Left;
}
Vector2f& SnakeBody::getHeadPositionReference() {
    return m_SnakeBody.getElementReference(HEADPOSITION);
}

void SnakeBody::clear() {
    m_SnakeBody.clear();
}
void SnakeBody::update() {
    for(int i = length(); i > 0; i--) {
        m_SnakeBody.setElement(m_SnakeBody[i-1], i);
    }

    switch(m_Dir) {
    case Direction::Up:
        getHeadPositionReference().x += 10;
        break;
    case Direction::Down:
        getHeadPositionReference().x -= 10;
        break;
    case Direction::Left:
        getHeadPositionReference().y += 10;
        break;
    case Direction::Right:
        getHeadPositionReference().y -= 10;
        break;
    }
}
bool SnakeBody::checkCollision(const Vector2f& pos, Collision c) {
    switch(c) {
    case Collision::Frucht:
        for(char i = 0; i < length(); i++) {
            if(pos == m_SnakeBody.getElement(i))
                return true;
        }
        return false;
        break;
    case Collision::Body:
        for(char i = 1; i < length(); i++) {
            if(pos == m_SnakeBody.getElement(i))
                return true;
        }
        return false;
        break;
    }

}

void SnakeBody::init() {
    clear();
    m_Dir = Direction::Left;
    m_SnakeBody.push(m_StartingPosition);
    m_SnakeBody.push(m_StartingPosition);
}
}