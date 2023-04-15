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

std::pair<int,int> ChessControler::follow_mouse(sf::Event::MouseMoveEvent mouse_event)
{
    /*
    This function is used to follow the mouse.
    If the mouse has been moved, the function returns the position of the mouse.
    Arguments:
        mouse_event: the mouse event
    Returns:
        mouse_position: the position of the mouse
    */
    std::pair<int,int> mouse_position;
    mouse_position.first = mouse_event.x;
    mouse_position.second = mouse_event.y;
    return mouse_position;
}

void  ChessControler::handle_events(sf::Event event, std::vector<PieceInfo> &pieces)
    {
        /*
        This function handles the events.
        Arguments:
            event: the event
        Returns:
            event_type: the type of the event
            mouse_position: the position of the mouse
        */
        switch (event.type)
        {
        case sf::Event::Closed:
            //do something to close the window, maybe pass the window this method?
            //return std::make_tuple("close",std::pair<int,int>(0,0));
        case sf::Event::MouseButtonPressed:
            check_mouse_click(event.mouseButton);
            //return std::make_tuple("click",check_mouse_click(event.mouseButton));
        case sf::Event::MouseButtonReleased:
            //return std::make_tuple("release",check_mouse_button_released(event.mouseButton));
        case sf::Event::MouseMoved:
            //return std::make_tuple("move",follow_mouse(event.mouseMove));
        }
    }

int ChessControler::check_click_on_piece(std::pair<int,int> mouse_position, std::vector<PieceInfo> &pieces)
{
    /*
    This function is used to check if the mouse has been clicked on a piece.
    If the mouse has been clicked on a piece, the function returns the index of the piece.
    Arguments:
        mouse_position: the position of the mouse
        pieces: Struct that contains the information about the pieces
    Returns:
        index: the index of the piece
    */
    for(int i = 0; i < pieces.size(); i++)
    {
        if(pieces[i].position.first == mouse_position.first && pieces[i].position.second == mouse_position.second)
        {
            return i;
        }
    }
    return -1;
}