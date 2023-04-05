#include "PawnPiece.h"

std::vector<std::pair<int,int>> PawnPiece::get_possible_moves() const {
    //Returns the possible moves of the piece
    std::vector<std::pair<int,int>> possible_moves;
    if (get_color() == "Black") {
        possible_moves.push_back(std::make_pair(get_position().first, get_position().second + 1));
    } else {
        possible_moves.push_back(std::make_pair(get_position().first, get_position().second - 1));
    }
    return possible_moves;
}