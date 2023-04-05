#include "MovesStacker.h"

MovesStacker::MovesStacker(std::pair<int,int> piece_position): m_piece_position(piece_position) {};

std::pair<int,int> MovesStacker::stack_move_in_direction(int direction, int number_of_moves) const
{
    /*
    Given a direction and a number of moves, this function returns the coordinates of the move,
    relative to the piece's position.
    For example, if the piece is in the position (0,0) and the direction is 1 and the number of moves is 2,
    the function will return (2,0).
    But if piece is in the position (1,1) and the direction is 2 and the number of moves is 3,
    the function will return (1,4).
    This direction system is used to make the code more readable.
    Here a diagram of the directions:
                            
                        6     5      4 
                        
                        7    Piece   3
                            (0,0)   
                            
                        8      1     2
    Arguments:
        direction: direction of the move
        number_of_moves: number of moves in the direction
    Returns:
        std::pair<int,int>: coordinates of the move
    */
    switch (direction)
    {
    case 1:
        return std::make_pair(m_piece_position.first, m_piece_position.second + number_of_moves);
        break;
    case 2:
        return std::make_pair(m_piece_position.first + number_of_moves, m_piece_position.second + number_of_moves);
        break;
    case 3:
        return std::make_pair(m_piece_position.first + number_of_moves, m_piece_position.second);
        break;
    case 4:
        return std::make_pair(m_piece_position.first + number_of_moves, m_piece_position.second - number_of_moves);
        break;
    case 5:
        return std::make_pair(m_piece_position.first, m_piece_position.second - number_of_moves);
        break;
    case 6:
        return std::make_pair(m_piece_position.first - number_of_moves, m_piece_position.second - number_of_moves);
        break;
    case 7:
        return std::make_pair(m_piece_position.first - number_of_moves, m_piece_position.second);
        break;
    case 8:
        return std::make_pair(m_piece_position.first - number_of_moves, m_piece_position.second + number_of_moves);
        break;
    default:
        return std::make_pair(0, 0);
        break;
    }
};
    
std::pair<int,int>MovesStacker::stack_move_coords(int x_moves, int y_moves) const
{
    /*
    Given a number of moves in the x axis and a number of moves in the y axis,
    this function returns the coordinates of the move, relative to the piece's position.
    For example, if the piece is in the position (0,0) and the x_moves is 2 and the y_moves is 1,
    the function will return (2,1).
    But if piece is in the position (1,1) and the x_moves is 3 and the y_moves is 2,
    the function will return (4,3).
    Arguments:
        x_moves: number of moves in the x axis
        y_moves: number of moves in the y axis
    Returns:
        std::pair<int,int>: coordinates of the move
    Warning:
        The coordinate system is x positive to the right and y positive to the bottom,
        because the board is represented as a matrix.
    */
    return std::make_pair(m_piece_position.first + x_moves, m_piece_position.second + y_moves);
};

std::vector<std::pair<int,int>> MovesStacker::stack_moves_in_direction(int direction, int number_of_moves, std::vector<std::pair<int,int>> possible_moves = {}) const
{
    /*
    This method stack a number of moves in a given direction, relative to the piece's position.
    This is used to stack moves in a given direction, for example, if the piece is in the position (0,0)
    and the direction is 1 and the number of moves is 2, the function will return the vector
    [(0,1), (0,2)].
    Usefull for Rook's moves or Bishop's moves.
    Arguments:
        direction: direction of the move
        number_of_moves: number of moves in the direction
        possible_moves: vector of possible moves
    Returns:
        std::vector<std::pair<int,int>>: vector of possible moves
    */
    for (int i = 1; i <= number_of_moves; i++)
    {
        possible_moves.push_back(stack_move_in_direction(direction, i));
    }
    return possible_moves;
    //Maybe use reference instead of return, but that way I modify the vector in the function, moves are not that expensive. 
};