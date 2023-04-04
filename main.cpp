#include <cassert>
#include "Board.h"
#include<iostream>

class ChessGame {

private:
    int m_turn{0};
    Board m_board;
    std::vector<std::pair<int,int>> m_pieces_positions;
    Piece * m_selected_piece{nullptr};
    Board m_board;
    sf::RenderWindow m_window;

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







};









int main() {
    Board board
        (
        std::make_pair(400, 400), 
        std::make_pair(0, 0), 
        32
        );
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chess Game");
    window.setFramerateLimit(30);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        board.draw_board(window);
        window.display();

    }
    return 0;
}