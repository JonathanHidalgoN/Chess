#include <string>
#include <vector>

#ifndef PIECE_H
#define PIECE_H

/*
 * Piece abstract base class
 * This class is responsible for creating the pieces.
 * Arguments:
 *   position: position of the piece
 *   name: name of the piece
 *   color: color of the piece
 *   is_alive: if the piece is alive or not
 *  images_path: path to the images of the pieces
 */


class Piece {
private:
    std::pair<int,int> m_position;
    std::string m_name;
    std::string m_color;
    bool m_is_alive;

public:
    Piece(
        std::pair<int,int> position,
        std::string name,
        std::string color,
        bool is_alive
    );
    Piece();

    std::pair<int,int> get_position() const;
    std::string get_name() const;
    std::string get_color() const;
    bool get_is_alive() const;
    void set_position(std::pair<int,int> new_position);
    void set_is_alive(bool is_alive);
};

#endif