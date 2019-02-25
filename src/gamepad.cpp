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
    for (int j = 0; j < 10; ++j) {
        std::cout << "\n\n\n\n";
    }

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

void gamepad::move_snake(int direction, bool & gameover) {
    if(!collision(m_snake->get_pos(), direction)) {
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
    } else {
        gameover = true;
    }

    if(m_snake->get_pos() == m_apple_pos) {
        m_apple_pos = rand() % m_gamepad_size + 1;

        //generate new apple pos as long as the rand apple pos is invalid
        while(collision(m_apple_pos, 0)) {
            m_apple_pos = rand() % m_gamepad_size + 1;
        }
        //std::cout << "apple_pos: " << m_apple_pos;
        m_snake->grow();
    }
}

bool gamepad::collision(int curr_pos, int direction) {
    int new_pos = 0;
    switch (direction) {
        case 1: //up
            new_pos = curr_pos - m_gamepad_len;
            break;
        case 2: //right
            new_pos = curr_pos + 1;
            break;
        case 3: //down
            new_pos = curr_pos + m_gamepad_len;
            break;
        case 4: //left
            new_pos = curr_pos - 1;
            break;
        default: //apple collision detection
            new_pos = curr_pos;
            break;
    }

    if(new_pos == -1) {
        throw std::invalid_argument("new_pos was not initialized");
    } else {
        //is curr pos in upper border?
        if((new_pos >= 0) && (new_pos <= m_gamepad_len)) {
            //std::cout << "top collision!" << std::endl;
            return true;

          //is curr pos in bottom border?
        } else if((new_pos >= m_gamepad_size - m_gamepad_len) && (new_pos <= m_gamepad_size)) {
            //std::cout << "bottom collision!" << std::endl;
            return true;

          //is curr pos in right and left border?
        } else if((new_pos % m_gamepad_len) == 0) {
            //std::cout << "left/right collision!" << std::endl;
            return true;
        }

        //bite yourself?
        if(m_snake->bitten(new_pos)) {
            //std::cout << "bite yourself!" << std::endl;
            return true;
        }
    }
    return false;
}
