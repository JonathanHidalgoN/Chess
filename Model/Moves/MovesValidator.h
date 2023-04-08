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
    MovesStacker m_moves_stacker;
    std::vector<std::pair<int, int>> compute_pawn_moves(std::pair<int,int> position,std::string const &color);
    std::vector<std::pair<int, int>> compute_knight_moves(std::pair<int,int> position);
    std::vector<std::pair<int, int>> compute_horse_moves(std::pair<int,int> position);
    std::vector<std::pair<int, int>> compute_rook_moves(std::pair<int,int> position);
    std::vector<std::pair<int, int>> compute_queen_moves(std::pair<int,int> position);
    std::vector<std::pair<int, int>> compute_king_moves(std::pair<int,int> position);

public:
    MovesValidator();
    std::vector<std::pair<int, int>> compute_valid_moves(Piece const &piece);

};




#endif