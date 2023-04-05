#ifndef HORSEPIECE_H
#define HORSEPIECE_H

#include "Piece.h"

class HorsePiece : public Piece {
    /*
    This class is responsible for creating the horse pieces.
    Arguments:
        position: position of the piece
        color: color of the piece
        is_alive: if the piece is alive or not
    Inherits from Piece class.
    */

public:
    HorsePiece(
        std::pair<int,int> position,
        std::string color,
        bool is_alive
    ) : Piece(position, "Horse", color, is_alive){}

};

#endif