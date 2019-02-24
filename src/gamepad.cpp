#include "gamepad.h"

gamepad::gamepad(int size) {
    //gamepad
    m_gamepad_len = size;
    m_gamepad_size = m_gamepad_len * m_gamepad_len;

    //snake
    int start_pos = (m_gamepad_size / 2) - (m_gamepad_len / 2);
    m_snake = new snake();
    m_snake->set_pos(start_pos);

    //apple
    m_apple_pos = rand() % m_gamepad_size + 1;
}

gamepad::~gamepad() {
    delete(m_snake);
}

void gamepad::draw() {
    for (int i = 0; i < m_gamepad_size; ++i) {
        if(((i % m_gamepad_len) == 0)){
            if(i == 0) {
                std::cout << std::endl << "|";
            } else {
                std::cout << "|" << std::endl << "|";
            }

        } else if((i < m_gamepad_len) || (i > m_gamepad_size - m_gamepad_len)) {
            std::cout << " - ";
        } else {
            if(m_snake->contains(i)) {
                std::cout << " # ";
            } else if(i == m_apple_pos) {
                std::cout << " O ";
            } else {
                std::cout << "   ";
            }
        }
    }
    std::cout << "|" << std::endl ;
}

//Todo collision detection !!!
void gamepad::move_snake(int direction) {

    switch (direction) {
        case 1: //up
            m_snake->up(m_gamepad_len);
            break;
        case 2: //right
            m_snake->right();
            break;
        case 3: //down
            m_snake->down(m_gamepad_len);
            break;
        case 4: //left
            m_snake->left();
            break;
    }

    if(m_snake->get_pos() == m_apple_pos) {
        m_apple_pos = (rand() % (m_gamepad_size - m_gamepad_len)) - m_gamepad_len;
        std::cout << "apple_pos: " << m_apple_pos;
        m_snake->grow();
    }
}
