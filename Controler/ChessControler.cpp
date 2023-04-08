#include "ChessControler.h"

ChessControler::ChessControler()
{
}

std::pair<int,int> ChessControler::check_mouse_click(sf::Event::MouseButtonEvent mouse_event)
{
    /*
    This function is used to check if the mouse has been clicked.
    If the mouse has been clicked, the function returns the position of the mouse.
    Arguments:
        mouse_event: the mouse event
    Returns:
        mouse_position: the position of the mouse
    */
    if(mouse_event.button == sf::Mouse::Left)
    {
        std::pair<int,int> mouse_position;
        mouse_position.first = mouse_event.x;
        mouse_position.second = mouse_event.y;
        return mouse_position;
    }
};