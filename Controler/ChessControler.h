#ifndef CHESSCONTROLER_H
#define CHESSCONTROLER_H
#include <SFML/Graphics.hpp>

class ChessControler
{

private:

    std::pair<int,int> check_mouse_click(sf::Event::MouseButtonEvent mouse_event);
    //std::pair<int,int> check_mouse_released(sf::Event::MouseMoveEvent mouse_event);

public:
    ChessControler();
    std::tuple<std::string,std::pair<int,int>> handle_events(sf::Event event);


};

#endif 