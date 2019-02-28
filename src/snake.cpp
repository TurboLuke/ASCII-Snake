#include "snake.h"

snake::snake() {
    m_snake_len = 1;
    m_body_pos = new std::vector<int>(m_snake_len);
}

snake::~snake() {
    delete m_body_pos;
}

void snake::grow() {
    m_snake_len++;
    m_body_pos->resize(m_snake_len);
}

//setter
void snake::set_pos(int pos) {
    for (int i = 0; i < m_snake_len; ++i) {
        m_body_pos->at(i) = pos + i;
    }
}

//movement
void snake::up(int gpad_len) {
    int head_pos = m_body_pos->front();
    m_body_pos->front() = m_body_pos->front() - gpad_len;

    move_rem_parts(head_pos);
}

void snake::right() {
    int head_pos = m_body_pos->front();
    m_body_pos->front() = m_body_pos->front() + 1;

    move_rem_parts(head_pos);
}

void snake::down(int gpad_len) {
    int head_pos = m_body_pos->front();
    m_body_pos->front() = m_body_pos->front() + gpad_len;

    move_rem_parts(head_pos);
}

void snake::left() {
    int head_pos = m_body_pos->front();
    m_body_pos->front() = m_body_pos->front() - 1;

    move_rem_parts(head_pos);
}

//some getters
int snake::get_pos() {
    return m_body_pos->front();
}

int snake::get_len() {
    return m_snake_len;
}

bool snake::contains(int i) {
    for (int j = 0; j < m_snake_len; ++j) {
        if(m_body_pos->at(j) == i) {
            return true;
        }
    }
    return false;
}

void snake::move_rem_parts(int head_pos) {
    int temp;
    for (int i = 1; i < m_snake_len; ++i) {
        temp = m_body_pos->at(i);
        m_body_pos->at(i) = head_pos;
        head_pos = temp;
    }
}

bool snake::bitten(int new_pos) {

    for (int i = 1; i < m_snake_len; ++i) {
        if(new_pos == m_body_pos->at(i)) {
            return true;
        }
    }
    return false;
}