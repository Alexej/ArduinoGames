#ifndef H_RENDERER
#define H_RENDERER
 
#include "../lib/TFT_Touch_Shield_V2-master/TFTv2.h"
#include "Vector2f.h"

namespace ArduinoEngine{
    class Renderer
    {
    private:
    public:
        void init();
        void test();
        void clear();
        void renderBorder(Vector2f pos, Vector2f size, int COLOR);
        void renderRectangle(Vector2f pos, Vector2f size, int COLOR);
        void renderText(char* str, Vector2f pos, int size, int color, TextOrientation te);
        void renderNumber(int n, Vector2f pos, int size, int color, TextOrientation te);
        void renderCircle(Vector2f pos, int r, int COLOR);
    };
}
#endif