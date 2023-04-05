#ifndef MOVESVALIDATOR_H
#define MOVESVALIDATOR_H

#include <vector>
#include <string>
#include "MovesStacker.h"
#include "../Pieces/Piece.h"



class MovesValidator {
  
    /*
    This class is responsible for generating piece moves.
    */

private:
    std::vector<std::pair<int, int>> compute_pawn_moves(Piece const &piece);
    std::vector<std::pair<int, int>> compute_knight_moves(Piece const &piece);
    std::vector<std::pair<int, int>> compute_horse_moves(Piece const &piece);
    std::vector<std::pair<int, int>> compute_rook_moves(Piece const &piece);
    std::vector<std::pair<int, int>> compute_queen_moves(Piece const &piece);
    std::vector<std::pair<int, int>> compute_king_moves(Piece const &piece);

public:
    MovesValidator();
    std::vector<std::pair<int, int>> compute_valid_moves(Piece const &piece, MovesStacker const &movesStacker);

};




#endif