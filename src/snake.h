#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

class snake {
private:
    int m_snake_len;
    std::vector<int> *m_body_pos;
    void move_rem_parts(int head_pos);

public:
    snake();
    ~snake();

    void grow();
    void set_pos(int pos);
    int get_pos(); //returns head pos
    int get_len();
    bool contains(int i);

    //movement
    void up(int gpad_len);
    void right();
    void down(int gpad_len);
    void left();

    //snake collision detection
    bool bitten(int new_pos);
};


