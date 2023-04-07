#ifndef CHESSRENDER_H
#define CHESSRENDER_H

#include <SFML/Graphics.hpp>

class ChessRender
{
private:
    sf::RenderWindow m_window;
    std::pair<unsigned int, unsigned int> m_board_size;
    void draw_piece(std::string name, std::pair<int, int> position, std::string color);
    void draw_board();
    void config_window(
        const unsigned int width,
        const unsigned int height,
        const std::string title,
        const unsigned int frame_rate
        );

public:
    ChessRender(
        const unsigned int width = 400,
        const unsigned int height = 600,
        const std::string title = "Chess",
        const unsigned int frame_rate = 60
    );

    void draw_chess();


};

#endif 