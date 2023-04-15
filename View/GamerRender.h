#ifndef CHESSRENDER_H
#define CHESSRENDER_H

#include <SFML/Graphics.hpp>
#include"BoardPixelMapper.h"
#include"../PieceInfo.h"

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
    std::pair<unsigned int, unsigned int> m_board_size;
    void draw_piece(const PieceInfo& piece_info);
    void draw_board();
    std::string map_name_to_file_name(std::string name, std::string color);
    void config_window(
        const unsigned int width,
        const unsigned int height,
        const std::string title,
        const unsigned int frame_rate
        );

public:
    sf::RenderWindow m_window;
    ChessRender(
        const unsigned int width = 400,
        const unsigned int height = 400,
        const std::string title = "Chess",
        const unsigned int frame_rate = 60
    );

    //Maybe delete this, not for now.
    bool is_open() const;
    bool render_game(sf::Event event, const std::vector<PieceInfo>& pieces_info);
    void draw_chess(const std::vector<PieceInfo>& pieces_info);
    std::pair<int,int> get_window_dims() const;
    std::pair<int,int> get_board_dims() const;

};

#endif 