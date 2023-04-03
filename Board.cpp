#include "Board.h"

Board::Board(
    //Constructor
    std::pair<int,int> board_dims,
    std::pair<int,int> board_position,
    int number_of_pieces
) {
    m_board_dims = board_dims;
    m_square_dims = assing_square_dims();
    m_board_position = board_position;
    m_number_of_pieces = number_of_pieces;
}

void Board::draw_board(sf::RenderWindow & window) {
    /*
    This method draws the board
    Arguments:
        window: The window to draw the board on
    */
    int square_widht = static_cast < int > (m_square_dims.first / 8);
    int square_height = static_cast < int > (m_square_dims.second / 8);
    sf::RectangleShape square(sf::Vector2f(square_widht, square_height));
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if ((row + col) % 2 == 0) {
                //This color is brown
                square.setFillColor(sf::Color(165, 42, 42));
            } else {
                square.setFillColor(sf::Color::White);
            }
            square.setPosition((col * square_height), (row * square_widht));
            window.draw(square);
        }
    }
}


void Board::draw_pawns(sf::RenderWindow & window) {
    for(int i{0}; i < 8; ++i){       
        std::string pawn_name = "pawn " + std::to_string(i);

    }
}

std::pair<int,int> Board::square_to_coords(std::pair<int,int> square_numbers)
{
    /*
    This function converts the square numbers to coordinates
    Arguments:
        square_numbers: The square numbers
    Returns:
        std::pair<int,int>: The coordinates
    */
    int x = square_numbers.first * m_square_dims.first;
    int y = square_numbers.second * m_square_dims.second;
    return std::make_pair(x, y);
}

std::pair<int,int> Board::assing_square_dims(){
    /*
    This function assigns the dimensions of the squares
    Returns:
        std::pair<int,int>: The dimensions of the squares
    */
    int square_width = static_cast<int>(m_board_dims.first / 8);
    int square_height = static_cast<int>(m_board_dims.second / 8);
    return std::make_pair(square_width, square_height);
}























