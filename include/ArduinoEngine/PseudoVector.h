#ifndef H_PSEUDOVECTOR
#define H_PSEUDOVECTOR

#include "Vector2f.h"

namespace ArduinoEngine{
    class PseudoVector
    {
        private:
            static constexpr int m_MAX_LENGTH = 300;
            int m_Length = 0;
            Vector2f m_PseudoVector[m_MAX_LENGTH];
        public:
            void push(Vector2f v){
                m_PseudoVector[m_Length] = v;
                m_Length++;
            }
            void pop(){
                m_Length--;
            }

            Vector2f& getElementReference(int i){
                return m_PseudoVector[i];
            }

            void setElement(Vector2f v, int i){
                m_PseudoVector[i] = v;
            }

            const Vector2f getElement(int i) const {
                return m_PseudoVector[i];
            }

            void clear(){
                m_Length = 0;
            }

            const int size() const {
                return m_Length;
            }

            Vector2f operator [](int i) {return m_PseudoVector[i];}
    };
}
#endif