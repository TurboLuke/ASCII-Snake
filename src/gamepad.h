#pragma once

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "snake.h"

class gamepad {
private:

    int m_gamepad_len;
    int m_gamepad_size;
    snake *m_snake;
    int m_apple_pos;

public:
    explicit gamepad(int size);
    ~gamepad();

    void draw();
    void move_snake(int direction);
};


