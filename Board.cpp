#include "Board.h"
Board::Board(
    //Constructor
    std::pair<int,int> board_dims,
    std::pair<int,int> board_position
) {
    m_board_dims = board_dims;
    m_square_dims = assing_square_dims();
}


std::pair<int,int> Board::get_board_dims() const {
    /*
    This method returns the dimensions of the board
    Returns:
        std::pair<int,int>: The dimensions of the board
    */
    return m_board_dims;
}

std::pair<int,int> Board::get_square_dims() const {
    /*
    This method returns the dimensions of the squares
    Returns:
        std::pair<int,int>: The dimensions of the squares
    */
    return m_square_dims;
}


std::pair<int,int> Board::assing_square_dims(){
    /*
    This method assigns the dimensions of the squares
    Returns:
        std::pair<int,int>: The dimensions of the squares
    */
    int square_width = static_cast<int>(m_board_dims.first / 8);
    int square_height = static_cast<int>(m_board_dims.second / 8);
    return std::make_pair(square_width, square_height);
}


