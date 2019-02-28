#include "game.h"
#define GAMEPAD_SIZE 10

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
    int curr_direction = 0;
    start_dialog();

    while(!m_gameover) {
        if (GetAsyncKeyState(VK_UP)) {           //UP Key
            curr_direction = UP;
        } else if (GetAsyncKeyState(VK_RIGHT)) { //RIGHT Key
            curr_direction = RIGHT;
        } else if (GetAsyncKeyState(VK_DOWN)) {  //DOWN Key
            curr_direction = DOWN;
        } else if (GetAsyncKeyState(VK_LEFT)) {  //LEFT Key
            curr_direction = LEFT;
        }

        if(curr_direction != 0) {
            m_gpad->move_snake(curr_direction, m_gameover);
            m_gpad->draw();
        }
        Sleep(400);
    }
    game_over_dialog();
}

void game::restart() {
    delete m_gpad;
    m_gpad = new gamepad(GAMEPAD_SIZE);
    m_gameover = false;
    this->start();
}

int game::end() {
    return EXIT_SUCCESS;
}

void game::game_over_dialog() {
    std::cout << "      ================" << std::endl;
    std::cout << "         GAME  OVER   " << std::endl;
    std::cout << "      ================" << std::endl;
    std::cout << "         SCORE: "       << m_gpad->get_score() << std::endl;
    std::cout << "        RESTART? y/n  " << std::endl;

    char restart;
    std::cin >> restart;

    if(restart == 'y') {
        this->restart();
    } else {
        this->end();
    }
}

void game::start_dialog() {
    std::cout << "      ================" << std::endl;
    std::cout << "         ASCII-SNAKE "  << std::endl;
    std::cout << "      ================" << std::endl;
    std::cout << "       USE ARROW KEYS"  << std::endl;
    std::cout << "        TO PLAY/START " << std::endl;
    std::cout << "          THE GAME"     << std::endl;
    std::cout << "      ================" << std::endl;
}





