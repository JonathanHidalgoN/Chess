#include"BoardPixelMapper.h"

BoardPixelMapper::BoardPixelMapper(
    const unsigned int board_width,
    const unsigned int board_height,
    const unsigned int window_width,
    const unsigned int window_height
) : m_board_size(board_width, board_height), m_window_size(window_width, window_height), m_square_size(compute_square_dims())
{
    //This constructor initializes the board size and the window size.
};

std::pair<unsigned int, unsigned int> BoardPixelMapper::compute_square_dims()
{
    //This function computes the dimensions of the squares.
    //Chess boards are 8x8.
    int NUMBER_OF_SQUARES = 8;
    unsigned int square_width = static_cast<unsigned int>(m_board_size.first / NUMBER_OF_SQUARES);
    unsigned int square_height = static_cast<unsigned int>(m_board_size.second / NUMBER_OF_SQUARES);
    return std::pair<unsigned int, unsigned int>(square_width, square_height);
};