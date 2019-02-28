#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "snake.h"

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

class gamepad {
private:
    int m_gamepad_len;
    int m_gamepad_size;
    snake *m_snake;
    int m_apple_pos;
    size_t m_score;

    bool collision(int curr_pos, int direction);

public:
    explicit gamepad(int size);
    ~gamepad();

    void draw();
    void move_snake(int direction, bool & gameover);
    size_t get_score();
};



