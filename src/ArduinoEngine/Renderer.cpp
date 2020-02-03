#include "../../include/ArduinoEngine/Renderer.h"

namespace ArduinoEngine {
void Renderer::init() {
    TFT_BL_ON;      // turn on the background light
    Tft.TFTinit();  // init TFT library
}

void Renderer::clear() {
    Tft.fillScreen();
}

void Renderer::test() {
    Tft.fillScreen(80, 160, 50, 150,RED);
    Tft.fillRectangle(30, 120, 100,65,YELLOW);
    Tft.drawRectangle(100, 170, 120,60,BLUE);
}


void Renderer::renderBorder(Vector2f pos, Vector2f size, int COLOR) {
    Tft.drawRectangle(pos.x, pos.y, size.x, size.y, COLOR);
}

void Renderer::renderRectangle(Vector2f pos, Vector2f size, int COLOR) {
    Tft.fillRectangle(pos.x, pos.y, size.x, size.y, COLOR);
}

void Renderer::renderCircle(Vector2f pos, int r, int COLOR) {
    Tft.fillCircle(pos.x, pos.y, r, COLOR);
}

void Renderer::renderText(char* str, Vector2f pos, int size,  int color, TextOrientation te) {
    Tft.drawString(str, pos.x, pos.y, size, color, te);
}

void Renderer::renderNumber(int n, Vector2f pos, int size, int color, TextOrientation te) {
    char snum[5];
    itoa(n, snum, 10);
    Tft.drawString(snum, pos.x, pos.y, size, color, te);
}
}


