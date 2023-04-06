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

std::vector<std::pair<int,int>> MovesValidator::compute_rook_moves(std::pair<int,int> position)
{
    /*
    This function is responsible for generating rook moves.
    Arguments:
        position: position of the rook
    Returns:
        possible_moves: vector of possible moves
    */
    std::vector<std::pair<int,int>> possible_moves = {};
    m_moves_stacker.change_piece(position);

    possible_moves = (m_moves_stacker.stack_moves_in_direction(1, 7, possible_moves));
    possible_moves = (m_moves_stacker.stack_moves_in_direction(3, 7, possible_moves));
    possible_moves = (m_moves_stacker.stack_moves_in_direction(5, 7, possible_moves));
    possible_moves = (m_moves_stacker.stack_moves_in_direction(7, 7, possible_moves));
    return possible_moves;
};

std::vector<std::pair<int,int>> MovesValidator::compute_valid_moves(Piece const & piece)
{
    /*
    This function is responsible for generating valid moves.
    Arguments:
        piece: piece for which we want to generate moves
    Returns:
        possible_moves: vector of possible moves
    */
    std::vector<std::pair<int,int>> possible_moves;
    std::string piece_type = piece.get_name();
    std::pair<int,int> position = piece.get_position();
    std::string color = piece.get_color();

    if (piece_type == "Pawn")
    {
        possible_moves = compute_pawn_moves(position, color);
    }
    else if (piece_type == "Rook")
    {
        possible_moves = compute_rook_moves(position);
    }
    return possible_moves;
};