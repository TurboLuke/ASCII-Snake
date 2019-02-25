#include "game.h"

game::game() {
    m_gpad = new gamepad(10);
    m_gameover = false;
}

game::game(int gamepad_size) {
    m_gpad = new gamepad(gamepad_size);
    m_gameover = false;
}

game::~game() {
    delete m_gpad;
}


void game::start() {

    m_gpad->draw();

    while(!m_gameover) {
        int key;
        if(kbhit()) {
            key = getch();
        }

        switch (key) {
            case 119: //w pressed
                m_gpad->move_snake(1, m_gameover);
                m_gpad->draw();
                break;
            case  97: //a pressed
                m_gpad->move_snake(4, m_gameover);
                m_gpad->draw();
                break;
            case 115: //s pressed
                m_gpad->move_snake(3, m_gameover);
                m_gpad->draw();
                break;
            case 100: //d pressed
                m_gpad->move_snake(2, m_gameover);
                m_gpad->draw();
                break;
            default:
                //do nothing
                break;
        }

    }

    //Game Over Dialog
    std::cout << "GAME OVER" << std::endl;
    std::cout << "RESTART? y/n" << std::endl;
    char restart;
    std::cin >> restart;

    if(restart == 'y') {
        this->restart();
    } else {
        this->end();
    }
}

void game::restart() {
    delete m_gpad;
    m_gpad = new gamepad(10); // 10 = size
    m_gameover = false;

    this->start();
}

int game::end() {
    return EXIT_SUCCESS;
}





