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
    set_up();
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
    draw_pieces(window);
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

int Board::get_number_of_pieces() const {
    /*
    This method returns the number of pieces
    Returns:
        int: The number of pieces
    */
    return m_number_of_pieces;
}

std::pair<int,int> Board::get_board_dims() const {
    /*
    This method returns the dimensions of the board
    Returns:
        std::pair<int,int>: The dimensions of the board
    */
    return m_board_dims;
}

std::pair<int,int> Board::get_square_dims() const {
    /*
    This method returns the dimensions of the squares
    Returns:
        std::pair<int,int>: The dimensions of the squares
    */
    return m_square_dims;
}

std::pair<int,int> Board::get_board_position() const {
    /*
    This method returns the position of the board
    Returns:
        std::pair<int,int>: The position of the board
    */
    return m_board_position;
}

std::pair<int,int> Board::square_to_coords(std::pair<int,int> square_numbers)
{
    /*
    This method converts the square numbers to coordinates
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
    This method assigns the dimensions of the squares
    Returns:
        std::pair<int,int>: The dimensions of the squares
    */
    int square_width = static_cast<int>(m_board_dims.first / 8);
    int square_height = static_cast<int>(m_board_dims.second / 8);
    return std::make_pair(square_width, square_height);
}

void Board::set_up_pawns()
{
    /*
    This method sets up the pawns for first turn
    return m_number_of_pieces;
    */
    for(int i{0}; i<8; ++i)
    {
        m_pieces[i] = Piece(
            std::make_pair(i, 1),
            "pawn" + std::to_string(i + 1), 
            "white", 
            true);
    }
    //Name for pawns are not unique, but the color is
    for(int i{8}; i<16; ++i)
    {
        m_pieces[i] = Piece(
            std::make_pair(i - 8, 6),
            "pawn" + std::to_string(i - 7), 
            "black", 
            true);
    }

}

void Board::set_up_rooks()
{
    /*
    This method sets up the rooks for first turn
    */
    m_pieces[16] = Piece(
        std::make_pair(0, 0),
        "rook 1", 
        "white", 
        true);
    m_pieces[17] = Piece(
        std::make_pair(7, 0),
        "rook 2", 
        "white", 
        true);
    m_pieces[18] = Piece(
        std::make_pair(0, 7),
        "rook 1", 
        "black", 
        true);
    m_pieces[19] = Piece(
        std::make_pair(7, 7),
        "rook 2", 
        "black", 
        true);    
}

void Board::set_up_bishops()
{
    /*
    This method sets up the bishops for first turn
    */
    m_pieces[20] = Piece(
        std::make_pair(2, 0),
        "bishop 1", 
        "white", 
        true);
    m_pieces[21] = Piece(
        std::make_pair(5, 0),
        "bishop 2", 
        "white", 
        true);
    m_pieces[22] = Piece(
        std::make_pair(2, 7),
        "bishop 1", 
        "black", 
        true);
    m_pieces[23] = Piece(
        std::make_pair(5, 7),
        "bishop 2", 
        "black", 
        true);    
}

void Board::set_up_king()
{
    /*
    This method sets up the kings for first turn
    */
    m_pieces[24] = Piece(
        std::make_pair(4, 0),
        "king", 
        "white", 
        true);
    m_pieces[25] = Piece(
        std::make_pair(4, 7),
        "king", 
        "black", 
        true);    
}

void Board::set_up_queen()
{
    /*
    This method sets up the queens for first turn
    */
    m_pieces[26] = Piece(
        std::make_pair(3, 0),
        "queen", 
        "white", 
        true);
    m_pieces[27] = Piece(
        std::make_pair(3, 7),
        "queen", 
        "black", 
        true);    
}

void Board::set_up_knights()
{
    /*
    This method sets up the knights for first turn
    */
    m_pieces[28] = Piece(
        std::make_pair(1, 0),
        "knight 1", 
        "white", 
        true);
    m_pieces[29] = Piece(
        std::make_pair(6, 0),
        "knight 2", 
        "white", 
        true);
    m_pieces[30] = Piece(
        std::make_pair(1, 7),
        "knight 1", 
        "black", 
        true);
    m_pieces[31] = Piece(
        std::make_pair(6, 7),
        "knight 2", 
        "black", 
        true);    
}

void Board::set_up(){
    /*
    This method sets up the board for the first turn
    */
    set_up_pawns();
    set_up_rooks();
    set_up_bishops();
    set_up_king();
    set_up_queen();
    set_up_knights();
}

void Board::draw_pieces(sf::RenderWindow& window)
{
    /*
    This method draws the pieces on the board
    Arguments:
        window: The window to draw on
    */
    for(int i{0}; i<m_number_of_pieces; ++i)
    {
        draw_piece(window, m_pieces[i]);        
    }
}
