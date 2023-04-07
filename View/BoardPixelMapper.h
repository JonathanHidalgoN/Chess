#ifndef BOARDPIXELMAPPER_H
#define BOARDPIXELMAPPER_H
//I don't know why I have to include this here.
#include <utility>

class BoardPixelMapper
{

//This class is used to map the board coordinates to pixel coordinates and vice versa.

private:
    const std::pair<unsigned int, unsigned int> m_board_size;
    const std::pair<unsigned int, unsigned int> m_window_size;

public:
    BoardPixelMapper(
        const unsigned int board_width,
        const unsigned int board_height,
        const unsigned int window_width,
        const unsigned int window_height
    );
    std::pair<unsigned int, unsigned int> transform_square_coords_to_pixel(std::pair<int, int> square_coords);
    std::pair<int, int> transform_pixel_coords_to_square(std::pair<unsigned int, unsigned int> pixel_coords);

};

#endif