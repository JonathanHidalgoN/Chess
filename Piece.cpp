#include "Piece.h"

Piece::Piece(
    std::pair<int,int> position,
    std::string name,
    std::string color,
    bool is_alive
) {
    m_position = position;
    m_name = name;
    m_color = color;
    m_is_alive = is_alive;
}

std::string Piece::map_name_to_file_name(){
    std::string piece_name = m_name.substr(0, m_name.size() - 2);
    if (m_color == "white") {
        return m_images_path + "/w_" + piece_name + ".png";
    } else {
        return m_images_path + "/b_" + piece_name + ".png";
    }
    return "";
}

std::pair<int,int> Piece::get_position() const {
    return m_position;
}

std::string Piece::get_name() const {
    return m_name;
}

std::string Piece::get_color() const {
    return m_color;
}

bool Piece::get_is_alive() const {
    return m_is_alive;
}

void Piece::set_position(std::pair<int,int> new_position) {
    m_position = new_position;
}
