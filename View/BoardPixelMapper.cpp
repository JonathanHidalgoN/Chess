#include"BoardPixelMapper.h"

BoardPixelMapper::BoardPixelMapper(
    const unsigned int board_width,
    const unsigned int board_height,
    const unsigned int window_width,
    const unsigned int window_height
) : m_board_size(board_width, board_height), m_window_size(window_width, window_height)
{
    //This constructor initializes the board size and the window size.
};

