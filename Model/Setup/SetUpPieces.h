#ifndef SETUPPIECES_H
#define SETUPPIECES_H

#include "../Pieces/Piece.h"
#include "../Pieces/PawnPiece.cpp"
#include "../Pieces/RookPiece.cpp"
#include "../Pieces/HorsePiece.cpp"
#include "../Pieces/BishopPiece.cpp"
#include "../Pieces/QueenPiece.cpp"
#include "../Pieces/KingPiece.cpp"

class SetUpPieces {
    /*
    This class is responsible for setting up the pieces on the board.
    */

private:
    Piece place_piece(std::pair<int,int> position, std::string name, std::string color);
    std::vector<Piece> place_initial_pawns();
    std::vector<Piece> place_initial_rooks();
    std::vector<Piece> place_initial_horses();
    std::vector<Piece> place_initial_bishops();
    std::vector<Piece> place_initial_queens();
    std::vector<Piece> place_initial_kings();

public:
    SetUpPieces();
    std::vector<Piece> place_initial_pieces();

    
};

#endif