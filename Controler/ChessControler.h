#ifndef CHESSCONTROLER_H
#define CHESSCONTROLER_H
#include <SFML/Graphics.hpp>

class ChessControler
{

private:

    std::pair<int,int> check_mouse_click(sf::Event::MouseButtonEvent mouse_event);


public:
    ChessControler();


};

#endif 