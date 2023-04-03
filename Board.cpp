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

void draw_piece(sf::RenderWindow & window, const Piece & piece) {
    /*
    This method draws a piece
    Arguments:
        window: The window to draw the piece on
        piece: The piece to draw
    */
    std::string file_name = piece.map_name_to_file_name();
    sf::Texture piece_texture;
    if(!piece_texture.loadFromFile(file_name)){
        //std::cout << "Error loading the piece texture" << std::endl;
    }
    //Check if the piece is alive
    if(piece.get_is_alive()){
        sf::Sprite piece_sprite;
        piece_sprite.setTexture(piece_texture);
        piece_sprite.setPosition(piece.get_position().first, piece.get_position().second);
        window.draw(piece_sprite);
    }
    else 
    {}
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






















