#ifndef BISHOPPIECE_H
#define BISHOPPIECE_H

#include "Piece.h"

class BishopPiece : public Piece {
    /*
    This class is responsible for creating the bishop pieces.
    Arguments:
        position: position of the piece
        color: color of the piece
        is_alive: if the piece is alive or not
    Inherits from Piece class.
    */

public:
    BishopPiece(
        std::pair<int,int> position,
        std::string color,
        bool is_alive
    ) : Piece(position, "Bishop", color, is_alive){}

};

#endif