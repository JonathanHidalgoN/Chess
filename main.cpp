#include <cassert>
#include "Board.h"
#include<iostream>

class ChessGame {
    /*
    This class is the main class of the game, manage the game loop and evnets.
    Attributes:
        m_turn (int): The turn of the game, 0 for white and 1 for black.
        m_board (Board): The board of the game.
        m_pieces_positions (std::vector<std::pair<int,int>>): The positions of the pieces.
        m_selected_piece (Piece*): The piece that is selected.
        m_window (sf::RenderWindow): The window of the game.
    */
private:
    int m_turn{0};
    Board m_board;
    std::vector<std::pair<int,int>> m_pieces_positions;
    Piece * m_selected_piece{nullptr};
    sf::RenderWindow m_window;

    void check_mouse_click_on_piece(sf::Event::MouseButtonEvent mouse_event)
    {
        /*
        This method checks if the mouse click is on a piece.
        Arguments:
            mouse_event (sf::Event::MouseButtonEvent): The mouse event.
        */
        if(mouse_event.button == sf::Mouse::Left)
        {
            //logic here
        }
    }

public:
    ChessGame():
        m_board(
            std::make_pair(400, 400), 
            std::make_pair(0, 0), 
            32
            ),
        m_window(sf::VideoMode(400, 400), "Chess Game")
    {
        m_window.setFramerateLimit(30);
    }

    void run()
    /*
    This method runs the game loop.
    */
    {
        while (m_window.isOpen()) {
            sf::Event event;
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    m_window.close();
                }
            }
            m_window.clear();
            m_board.draw_board(m_window);
            m_window.display();
        }
    }
};


int main() {
    ChessGame game;
    game.run();
    return 0;
}