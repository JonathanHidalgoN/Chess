#ifndef CHESSRENDER_H
#define CHESSRENDER_H

#include <SFML/Graphics.hpp>
#include"BoardPixelMapper.h"


class ChessRender
{
    /*
    This class is used to render the chess game.
    Arguments:
        width: The width of the window.
        height: The height of the window.
        title: The title of the window.
        frame_rate: The frame rate of the window.
    */
private:
    sf::RenderWindow m_window;
    std::pair<unsigned int, unsigned int> m_board_size;
    void draw_piece(std::string name, std::pair<int, int> position, std::string color);
    BoardPixelMapper m_board_pixel_mapper;
    void draw_board();
    std::string map_name_to_file_name(std::string name, std::string color);
    void config_window(
        const unsigned int width,
        const unsigned int height,
        const std::string title,
        const unsigned int frame_rate
        );

public:
    ChessRender(
        const unsigned int width = 400,
        const unsigned int height = 400,
        const std::string title = "Chess",
        const unsigned int frame_rate = 60
    );

    void draw_chess();
    //Maybe delete this, not for now.
    bool is_open() const;
    bool render_game(sf::Event event);


};

#endif 