#include "MovesValidator.h"

MovesValidator::MovesValidator() : m_moves_stacker(std::make_pair(0, 0)) {}

std::vector<std::pair<int,int>> MovesValidator::compute_pawn_moves(std::pair<int,int> position,std::string const &color)
{
    /*
    This function is responsible for generating pawn moves.
    Arguments:
        position: position of the pawn
        color: color of the pawn
    Returns:
        possible_moves: vector of possible moves
    */
    std::vector<std::pair<int,int>> possible_moves;
    m_moves_stacker.change_piece(position);

    if (color == "White")
    {
        possible_moves = (m_moves_stacker.stack_moves_in_direction(5, 1));  
    }
    else if (color == "Black")
    {
        possible_moves = (m_moves_stacker.stack_moves_in_direction(3, 1));
    }
    return possible_moves;
};