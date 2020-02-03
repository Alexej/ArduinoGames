#include "../../../include/Tic/States/TikState.h"

namespace Tik{
    TikState::TikState(StateManager& sm, Renderer& rd, Joystick& js) : State(sm, rd, js){}
    void TikState::handleInput(){
        if(m_TS.isTouching()){
            m_ShieldIsPressed = true;
            m_Point = m_TS.getPoint();
            m_Point.x = map(m_Point.x, TS_MINX, TS_MAXX, 0, 240);
            m_Point.y = map(m_Point.y, TS_MINY, TS_MAXY, 0, 320);
            if(m_Point.x > 40 && m_Point.x < 90 && m_Point.y > 260 && m_Point.y < 310){
                m_Renderer.renderText("E",Vector2f(270, 47), 4, BRIGHT_RED, TextOrientation::LANDSCAPE);
                m_StateManager.changeState(ArduinoEngine::States::Menu);
            }


            if(m_Point.x > 100 && m_Point.x < 150 && m_Point.y > 260 && m_Point.y < 310){
                m_Renderer.renderText("A",Vector2f(270, 107), 4, BRIGHT_RED, TextOrientation::LANDSCAPE);
                m_StateManager.changeState(ArduinoEngine::States::Tic);
            }


            if(m_Point.x > 4 && m_Point.x < 231 && m_Point.y > 4 && m_Point.y < 241 && m_isRunning){

                // Last Row
                if(m_Point.x > 5 && m_Point.x < 80 && m_Point.y > 5 && m_Point.y < 80){
                    if(checkIfCellFree(0)){
                        m_Field[0] = "X";
                        drawXO("X", 0, GREEN);AI();
                    }
                }

                if(m_Point.x > 5 && m_Point.x < 80 && m_Point.y > 80 && m_Point.y < 155){
                    if(checkIfCellFree(1)){
                        m_Field[1] = "X";
                        drawXO("X", 1, GREEN); AI();
                    }
                }

                if(m_Point.x > 5 && m_Point.x < 80 && m_Point.y > 155 && m_Point.y < 230){
                    if(checkIfCellFree(2)){
                        m_Field[2] = "X";
                        drawXO("X", 2, GREEN);AI();
                    }
                }
                
                //Second row
                if(m_Point.x > 80 && m_Point.x < 155 && m_Point.y > 5 && m_Point.y < 80){
                    if(checkIfCellFree(3)){
                        m_Field[3] = "X";
                        drawXO("X", 3, GREEN); AI();
                    }
                }

                if(m_Point.x > 80 && m_Point.x < 155 && m_Point.y > 80 && m_Point.y < 155){
                    if(checkIfCellFree(4)){
                        m_Field[4] = "X";
                        drawXO("X", 4, GREEN); AI();
                    }
                }

                if(m_Point.x > 80 && m_Point.x < 155 && m_Point.y > 155 && m_Point.y < 230){
                    if(checkIfCellFree(5)){
                        m_Field[5] = "X";
                        drawXO("X", 5, GREEN); AI();
                    }
                }

                //First row
                if(m_Point.x > 155 && m_Point.x < 230 && m_Point.y > 5 && m_Point.y < 80){
                    if(checkIfCellFree(6)){
                        m_Field[6] = "X";
                        drawXO("X", 6, GREEN); AI();
                    }
                }

                if(m_Point.x > 155 && m_Point.x < 230 && m_Point.y > 80 && m_Point.y < 155){
                    if(checkIfCellFree(7)){
                        m_Field[7] = "X";
                        drawXO("X", 7, GREEN); AI();
                    }
                }

                if(m_Point.x > 155 && m_Point.x < 230 && m_Point.y > 155 && m_Point.y < 230){
                    if(checkIfCellFree(8)){
                        m_Field[8] = "X";
                        drawXO("X", 8, GREEN); AI();
                    }
                }
            }
            if(checkWin(m_Field, "X")){
                m_isRunning = false;
            }
            if(checkWin(m_Field, "O")){
                m_isRunning = false;
            }
        }
    }
    void TikState::updateState(){}
    void TikState::init(){
        m_isRunning = true;
        for(int i = 0; i < 9; i++){
            m_Field[i] =  " ";
        }
        m_StateManager.setDelay(m_Delay); 
        m_Renderer.clear();
        m_Renderer.renderBorder(Vector2f(4,4), Vector2f(231,241),BLUE);
        m_Renderer.renderBorder(Vector2f(40, 260), Vector2f(50,50), BLUE);
        m_Renderer.renderText("E",Vector2f(270, 47), 4, WHITE, TextOrientation::LANDSCAPE);

        m_Renderer.renderBorder(Vector2f(100, 260), Vector2f(50,50), BLUE);
        m_Renderer.renderText("A",Vector2f(270, 107), 4, WHITE, TextOrientation::LANDSCAPE);


        m_Renderer.renderRectangle(Vector2f(80, 5), Vector2f(1,239), BLUE);
        m_Renderer.renderRectangle(Vector2f(160, 5), Vector2f(1,239), BLUE);
        
        m_Renderer.renderRectangle(Vector2f(5, 80), Vector2f(229,1), BLUE);
        m_Renderer.renderRectangle(Vector2f(5, 165), Vector2f(229,1), BLUE);

    }
    void TikState::draw(){}

    bool TikState::checkIfCellFree(int i){
        if(m_Field[i] == " "){
            return true;
        }
        return false;
    }
    bool TikState::checkWin(char** f, char* p){
        if(f[0] == f[1] && f[1] == f[2] && f[2] == p){return true;}
        if(f[3] == f[4] && f[4] == f[5] && f[5] == p){return true;}
        if(f[6] == f[7] && f[7] == f[8] && f[8] == p){return true;}
        if(f[0] == f[3] && f[3] == f[6] && f[6] == p){return true;}
        if(f[1] == f[4] && f[4] == f[7] && f[7] == p){return true;}
        if(f[2] == f[5] && f[5] == f[8] && f[8] == p){return true;}
        if(f[0] == f[4] && f[4] == f[8] && f[8] == p){return true;}
        if(f[2] == f[4] && f[4] == f[6] && f[6] == p){return true;}
        return false;
    }
    void TikState::drawXO(char* c, int i, int COLOR = WHITE){
        switch(i){
            case 0: m_Renderer.renderText(c, Vector2f(12,8), 8, COLOR, TextOrientation::LANDSCAPE); break;
            case 1: m_Renderer.renderText(c, Vector2f(14+80,8), 8, COLOR, TextOrientation::LANDSCAPE); break;
            case 2: m_Renderer.renderText(c, Vector2f(16+2*80,8), 8, COLOR, TextOrientation::LANDSCAPE); break;
            case 3: m_Renderer.renderText(c, Vector2f(12,8+77), 8, COLOR, TextOrientation::LANDSCAPE);break;
            case 4: m_Renderer.renderText(c, Vector2f(14+80,8+77), 8, COLOR, TextOrientation::LANDSCAPE); break;
            case 5: m_Renderer.renderText(c, Vector2f(16+2*80,8+77), 8, COLOR, TextOrientation::LANDSCAPE); break;
            case 6: m_Renderer.renderText(c, Vector2f(12,8+2*77), 8, COLOR, TextOrientation::LANDSCAPE);break;
            case 7: m_Renderer.renderText(c, Vector2f(14+80,8+2*77), 8, COLOR, TextOrientation::LANDSCAPE);break;
            case 8: m_Renderer.renderText(c, Vector2f(16+2*80, 8+2*77), 8, COLOR, TextOrientation::LANDSCAPE);break;
        }
    }
    void TikState::AI(){
        int move = findBestMove();
        m_Field[move] = "O";
        drawXO("O", move, BRIGHT_RED);
    }

    int TikState::findBestMove(){
        m_Renderer.renderText("I",Vector2f(270, 177), 4, BRIGHT_RED, TextOrientation::LANDSCAPE);
        int bestVal = -1000;
        int index = -1;
        for(int i = 0; i < 9; i++){
            if(m_Field[i] == " "){
                m_Field[i] = "O";
                int tmp = minimax(m_Field, 0, false);
                m_Field[i] = " ";
                if(tmp > bestVal){
                    index = i;
                    bestVal = tmp;
                }
            }
        }
        m_Renderer.renderText("I",Vector2f(270, 177), 4, BLACK, TextOrientation::LANDSCAPE);
        return index;
    }
    bool TikState::movesLeft(char** f){
        bool state = false;
        for(int i = 0; i < 9; i++){
            if(f[i] == " "){
                return true;
            }
        }
        return state;
    }
    int TikState::minimax(char** m, int depth,   bool isMax){
        int score = evaluate(m);
        if(score == 1){
            return score;
        }
        if(score == -1){
            return score;
        }
        if(!movesLeft(m)){
            return 0;
        }

        if(isMax){
            int best = -1000;
            for(int i = 0; i < 9; i++){
                if(m[i] == " "){
                    m[i] = "O";
                    int tmpMinMax = minimax(m, depth+1, !isMax);
                    best = best > tmpMinMax ? best : tmpMinMax;
                    m[i] = " ";
                }
            }
            return best;
        }
        else{
            int best = 1000;
            for(int i = 0; i < 9; i++){
                if(m[i] == " "){
                    m[i] = "X";
                    int tmpMinMax = minimax(m, depth+1, !isMax);
                    best = best > tmpMinMax ? tmpMinMax : best;
                    m[i] = " ";
                }
            }
            return best;
        }
        
    }

    int TikState::evaluate(char** f){
        if(checkWin(f, "X")){
            return -1;
        } else if(checkWin(f, "O")){
            return 1;
        }
        return 0;
    }
    void TikState::drawCurrentState(char** m){
        Serial.print("---------");
        Serial.println(" ");
        for(int i = 0; i <= 2; i++){
            Serial.print(m_Field[i]);
            Serial.print(" | ");
        }
        Serial.println(" ");
        Serial.print("---------");
        Serial.println(" ");
        for(int i = 3; i <= 5; i++){
            Serial.print(m_Field[i]);
            Serial.print(" | ");
        }
        Serial.println(" ");
        Serial.print("---------");
        Serial.println(" ");
        for(int i = 6; i <= 8; i++){
            Serial.print(m_Field[i]);
            Serial.print(" | ");
        }
        Serial.println("                   ");
        Serial.println("                   ");
        Serial.println("                   ");

    }

}