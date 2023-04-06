#ifndef SETUPPIECES_H
#define SETUPPIECES_H

#include "../Pieces/Piece.h"
#include "../Pieces/PawnPiece.h"
#include "../Pieces/RookPiece.h"
#include "../Pieces/HorsePiece.h"
#include "../Pieces/BishopPiece.h"
#include "../Pieces/QueenPiece.h"
#include "../Pieces/KingPiece.h"

class SetUpPieces {
    /*
    This class is responsible for setting up the pieces on the board.
    */

private:
    Piece place_piece(std::pair<int,int> position, std::string name, std::string color);
    std::vector<Piece> place_initial_pawns();
    std::vector<Piece> place_initial_rooks();
    std::vector<Piece> place_initial_knights();
    std::vector<Piece> place_initial_bishops();
    std::vector<Piece> place_initial_queens();
    std::vector<Piece> place_initial_kings();

public:
    SetUpPieces();
    std::vector<Piece> place_initial_pieces(std::vector<Piece> &pieces);

    
};

#endif