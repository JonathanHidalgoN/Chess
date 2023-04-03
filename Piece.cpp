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

Piece::Piece()
{
    //Default constructor
    m_position = std::make_pair(0, 0);
    m_name = "";
    m_color = "";
    m_is_alive = false;
}

std::string Piece::map_name_to_file_name(){
    /*
    This function maps the name of the piece to the file name.
    Returns:
        std::string: file name
    */
    //Piece name is in the format "name number, for example "pawn 1"
    //We want to remove the number from the name
    std::string piece_name = m_name.substr(0, m_name.size() - 2);
    if (m_color == "white") {
        return m_images_path + "/w_" + piece_name + ".png";
    } else {
        return m_images_path + "/b_" + piece_name + ".png";
    }
    return "";
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
