#ifndef PawnPiece_H
#define PawnPiece_H

#include "Piece.h"

class PawnPiece : public Piece {
    /*
    This class is responsible for creating the pawn pieces.
    Arguments:
        position: position of the piece
        color: color of the piece
        is_alive: if the piece is alive or not
    Inherits from Piece class.
    */
public:
    PawnPiece(
        std::pair<int,int> position,
        std::string color,
        bool is_alive
    ) : Piece(position, "Pawn", color, is_alive){}

};

#endif