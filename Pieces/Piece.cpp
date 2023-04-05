#include "Piece.h"

Piece::Piece(
    std::pair<int,int> position,
    std::string name,
    std::string color,
    bool is_alive
) {
    //Constructor
    m_position = position;
    m_name = name;
    m_color = color;
    m_is_alive = is_alive;
}


std::pair<int,int> Piece::get_position() const {
    //Returns the position of the piece
    return m_position;
}

std::string Piece::get_name() const {
    //Returns the name of the piece
    return m_name;
}

std::string Piece::get_color() const {
    //Returns the color of the piece
    return m_color;
}

bool Piece::get_is_alive() const {
    //Returns if the piece is alive or not
    return m_is_alive;
}

void Piece::set_position(std::pair<int,int> new_position) {
    //Sets the position of the piece
    m_position = new_position;
}

void Piece::set_is_alive(bool new_status) {
    //Sets the alive status of the piece
    m_is_alive = new_status;
}

std::vector<std::pair<int,int>> Piece::get_possible_moves() const {
    //Returns the possible moves of the piece
    return std::vector<std::pair<int,int>>();
}