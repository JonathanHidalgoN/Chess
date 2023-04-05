#ifndef KINGPIECE_H
#define KINGPIECE_H

#include "Piece.h"

class KingPiece : public Piece {
    /*
    This class is responsible for creating the king pieces.
    Arguments:
        position: position of the piece
        color: color of the piece
        is_alive: if the piece is alive or not
    Inherits from Piece class.
    */
public:
    KingPiece(
        std::pair<int,int> position,
        std::string color,
        bool is_alive
    ) : Piece(position, "King", color, is_alive){}
};

#endif