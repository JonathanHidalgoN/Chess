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

std::pair<int,int> ChessControler::check_mouse_button_released(sf::Event::MouseButtonEvent mouse_event)
{
    /*
    This function is used to check if the mouse has been released.
    If the mouse has been released, the function returns the position of the mouse.
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
    //Maybe this is not the best way to do it
    return std::pair<int,int>(-1,-1);
};

std::tuple<std::string,std::pair<int,int>> ChessControler::handle_events(sf::Event event)
    {
        /*
        This function handles the events.
        */
        switch (event.type)
        {
        case sf::Event::Closed:
            //do something to close the window, maybe pass the window this method?
            return std::make_tuple("close",std::pair<int,int>(0,0));
            break;
        case sf::Event::MouseButtonPressed:
            check_mouse_click(event.mouseButton);
            return std::make_tuple("click",check_mouse_click(event.mouseButton));
            break;
        }
    }