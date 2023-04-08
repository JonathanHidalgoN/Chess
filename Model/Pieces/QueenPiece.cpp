#ifndef QUEENPIECE_H
#define QUEENPIECE_H

#include "Piece.h"

class QueenPiece : public Piece {
    /*
    This class is responsible for creating the queen pieces.
    Arguments:
        position: position of the piece
        color: color of the piece
        is_alive: if the piece is alive or not
    Inherits from Piece class.
    */

public:
    QueenPiece(
        std::pair<int,int> position,
        std::string color,
        bool is_alive
    ) : Piece(position, "Queen", color, is_alive){}

};

#endif
