#include <cassert>
#include "Board.h"
#include<iostream>

class ChessGame {

private:
    sf::RenderWindow m_window;
    sf::Event m_event;
    Board m_board;
 

public:
    ChessGame() : 
    m_board
        (
        std::make_pair(800, 800), 
        std::make_pair(800, 800), 
        std::make_pair(0, 0), 32
        )
    {
        m_window.create(sf::VideoMode(800, 800), "Chess Game");
        m_window.setFramerateLimit(60);
        while (m_window.isOpen()) {
            while (m_window.pollEvent(m_event)) {
                if (m_event.type == sf::Event::Closed) {
                    m_window.close();
                }
            }
            m_board.draw_board(m_window);
            m_window.clear();
            m_window.display();
        }
    }


};

int main() {
    ChessGame game;
    return 0;
}