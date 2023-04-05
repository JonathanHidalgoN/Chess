#ifndef ROOKPIECE_H
#define ROOKPIECE_H

#include "Piece.h"

class RookPiece : public Piece {
    /*
    This class is responsible for creating the rook pieces.
    Arguments:
        position: position of the piece
        color: color of the piece
        is_alive: if the piece is alive or not
    Inherits from Piece class.
    */
public:
    RookPiece(
        std::pair<int,int> position,
        std::string color,
        bool is_alive
    ) : Piece(position, "Rook", color, is_alive){}

};

#endif