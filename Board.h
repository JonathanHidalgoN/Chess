#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Piece.h"

#ifndef BOARD_H
#define BOARD_H


class Board {

private:
    std::pair<int,int> m_board_dims;
    std::pair<int,int> m_square_dims;
    std::pair<int,int> m_board_position;
    int m_number_of_pieces;
    std::vector<Piece> m_pieces;
    std::pair<int,int> assing_square_dims();
    std::pair<int,int> square_to_coords(std::pair<int,int> square_numbers);    
    void set_up_pawns();
    void set_up_rooks();
    void set_up_knights();
    void set_up_bishops();
    void set_up_queen();
    void set_up_king();
    void set_up();
    void draw_piece(sf::RenderWindow& window, const Piece& piece);
    void draw_pieces(sf::RenderWindow& window);

public:
    Board(
        std::pair<int,int> board_dims,
        std::pair<int,int> board_position,
        int number_of_pieces
    );
    void draw_board(sf::RenderWindow& window);
    std::pair<int,int> get_board_dims() const;
    std::pair<int,int> get_square_dims() const;
    std::pair<int,int> get_board_position() const;
    int get_number_of_pieces() const;
    std::vector<Piece> get_pieces() const;

};

#endif