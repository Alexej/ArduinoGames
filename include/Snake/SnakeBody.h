#ifndef H_SNAKE
#define H_SNAKE

#include "../ArduinoEngine/Vector2f.h"
#include "../ArduinoEngine/PseudoVector.h"

using ArduinoEngine::PseudoVector;

namespace Snake{
    enum Collision {Frucht, Body};
    enum Direction {Left = 0, Right = 1, Up = 2, Down = 3};
    class SnakeBody{
    private:
    const bool HEADPOSITION = 0;
        const Vector2f m_StartingPosition = Vector2f(100, 120);
        PseudoVector m_SnakeBody;
        Direction m_Dir;
    public:
        const Vector2f getHeadPosition() const;
        void setDirectionUp();
        void setDirectionDown();
        void setDirectionRight();
        void setDirectionLeft();
        Vector2f& getHeadPositionReference();
        void update();
        void init();
        void clear();
        bool checkCollision(const Vector2f& pos, Collision c);
        const int length() const { 
            return m_SnakeBody.size();
        }

        const Vector2f getSnakeElement(int i) const {
            return m_SnakeBody.getElement(i);
        }

        void push(Vector2f v){
            m_SnakeBody.push(v);
        }

        const Direction& getDirection() const {
            return m_Dir;
        }
    };
}
#endif