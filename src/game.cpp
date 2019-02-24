#include "game.h"

game::game() {
    m_gpad = new gamepad(12);
    m_gameover = false;
}

game::~game() {
    delete m_gpad;
}

void game::start() {
    int key;
    m_gpad->draw();

    while(!m_gameover) {

        key = _getch();
        switch (key) {
            case 119: //w pressed
                m_gpad->move_snake(1);
                m_gpad->draw();
                break;
            case  97: //a pressed
                m_gpad->move_snake(4);
                m_gpad->draw();
                break;
            case 115: //s pressed
                m_gpad->move_snake(3);
                m_gpad->draw();
                break;
            case 100: //d pressed
                m_gpad->move_snake(2);
                m_gpad->draw();
                break;
        }
    }
}

void game::restart() {
 //Todo
}

int game::end() {
 //Todo
}




