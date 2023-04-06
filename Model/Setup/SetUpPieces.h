#ifndef SETUPPIECES_H
#define SETUPPIECES_H

#include "../Pieces/Piece.h"

class SetUpPieces {
    /*
    This class is responsible for setting up the pieces on the board.
    */

private:
    std::vector<Piece> place_piece(Piece &piece, int x, int y);
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