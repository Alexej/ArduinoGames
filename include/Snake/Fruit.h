#ifndef H_FRUIT
#define H_FRUIT7

#include "../ArduinoEngine/Vector2f.h"
#include "Arduino.h"

namespace Snake{
    class Fruit
    {
    private:
        Vector2f m_Pos;
    public:
        Fruit()
        {
            setFruitPosition();
        }

        void setFruitPosition(){
            m_Pos.x = random(1,21);
            m_Pos.y = random(1,22);
            m_Pos.x *= 10;
            m_Pos.y *= 10;
        }
        const Vector2f getPosition() const{
            return m_Pos;
        }
    };
}
#endif