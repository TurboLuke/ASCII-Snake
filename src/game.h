#pragma once
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "gamepad.h"
#include "snake.h"

class game {
private:
    bool m_gameover;
    gamepad *m_gpad;

public:
    game();
    explicit game(int gamepad_size);
    ~game();

    void start();
    void restart();
    int end();
};

