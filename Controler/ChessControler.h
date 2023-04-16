#ifndef CHESSCONTROLER_H
#define CHESSCONTROLER_H
#include <SFML/Graphics.hpp>
#include"../PieceInfo.h"


class ChessControler
{

private:
    int m_selected_piece_index;
    std::pair<int,int> check_mouse_click(sf::Event::MouseButtonEvent mouse_event);
    std::pair<int,int> check_mouse_button_released(sf::Event::MouseButtonEvent mouse_event);
    std::pair<int,int> follow_mouse(sf::Event::MouseMoveEvent mouse_event);
    int check_click_on_piece(std::pair<int,int> mouse_position, const std::vector<PieceInfo> &pieces);
    void handle_clicks(sf::Event event, const std::vector<PieceInfo> &pieces);
    void handle_moving_mouse(sf::Event event, std::vector<PieceInfo> &pieces);
    void handle_released_mouse(sf::Event event, std::vector<PieceInfo> &pieces);

public:
    ChessControler();
    void handle_events(sf::Event event, std::vector<PieceInfo> &pieces);


};

#endif 