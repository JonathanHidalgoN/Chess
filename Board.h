#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Piece.h"

#ifndef BOARD_H
#define BOARD_H

/*
 * Board class
 * This class is responsible for creating the board.
 * Arguments:
 *   board_dims: dimensions of the board
 *   board_position: position of the board
 */

class Board {

private:
    std::pair<int,int> m_board_dims;
    std::pair<int,int> m_square_dims;
    std::pair<int,int> assing_square_dims();
public:
    Board(
        std::pair<int,int> board_dims,
        std::pair<int,int> board_position
    );
    std::pair<int,int> get_board_dims() const;
    std::pair<int,int> get_square_dims() const;

};

#endif