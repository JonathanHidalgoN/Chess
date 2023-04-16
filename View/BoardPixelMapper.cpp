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

std::pair<unsigned int, unsigned int> BoardPixelMapper::compute_square_dims() const
{
    //This function computes the dimensions of the squares.
    //Chess boards are 8x8.
    int NUMBER_OF_SQUARES = 8;
    unsigned int square_width = static_cast<unsigned int>(m_board_size.first / NUMBER_OF_SQUARES);
    unsigned int square_height = static_cast<unsigned int>(m_board_size.second / NUMBER_OF_SQUARES);
    return std::pair<unsigned int, unsigned int>(square_width, square_height);
};

std::pair<unsigned int, unsigned int> BoardPixelMapper::transform_square_coords_to_pixel(std::pair<int, int> square_coords) const
{
    /*
    This function transforms the square coordinates to pixel coordinates.
    Arguments:
        square_coords: The square coordinates.
    Returns:
        The pixel coordinates.
    */
    unsigned int x = static_cast<unsigned int>(square_coords.first * m_square_size.first);
    unsigned int y = static_cast<unsigned int>(square_coords.second * m_square_size.second);
    return std::pair<unsigned int, unsigned int>(x, y);
};

std::pair<int, int> BoardPixelMapper::transform_pixel_coords_to_square(std::pair<unsigned int, unsigned int> pixel_coords) const
{
    /*
    This function transforms the pixel coordinates to square coordinates.
    Arguments:
        pixel_coords: The pixel coordinates.
    Returns:
        The square coordinates.
    */
    int x = static_cast<int>(pixel_coords.first / m_square_size.first);
    int y = static_cast<int>(pixel_coords.second / m_square_size.second);
    return std::pair<int, int>(x, y);
};

bool BoardPixelMapper::check_if_piece_is_there(std::pair<int,int> piece_coords, std::pair<int,int> mouse_coords) const
{
    //I do this mix coords because piece corods are in squares and mouse coords are in pixels.
    /*
    This function checks if the mouse is over a piece.
    Arguments:
        piece_coords: The coordinates of the piece in squares.
        mouse_coords: The coordinates of the mouse in pixels.
    Returns:
        True if the mouse is over the piece, false otherwise.
    */
    std::pair<unsigned int, unsigned int> mouse_square_coords = transform_pixel_coords_to_square(mouse_coords);
    if (mouse_square_coords.first == piece_coords.first && mouse_square_coords.second == piece_coords.second)
    {
        return true;
    }
    return false;
};
