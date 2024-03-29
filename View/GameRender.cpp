#include"GameRender.h"

ChessRender::ChessRender(
    const unsigned int width,
    const unsigned int height,
    const std::string title,
    const unsigned int frame_rate
) : m_board_size(width, height)  
{
    config_window(width, height, title, frame_rate);    
};

void ChessRender::config_window(
    const unsigned int width,
    const unsigned int height,
    const std::string title,
    const unsigned int frame_rate
)
{
    /*
    This function configures the window.
    Arguments:
        width: The width of the window.
        height: The height of the window.
        title: The title of the window.
        frame_rate: The frame rate of the window.
    */
    m_window.create(sf::VideoMode(width, height), title);
    m_window.setFramerateLimit(frame_rate);
}

void ChessRender::draw_board()
    /*
    This function draws the board. It is called by draw_chess().
    */
{
    std::pair<unsigned int, unsigned int> square_dims = {
        m_board_size.first / 8,
        m_board_size.second / 8
    };
    sf::RectangleShape square(sf::Vector2f(square_dims.first, square_dims.second));
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if ((row + col) % 2 == 0) {
                //This color is brown
                square.setFillColor(sf::Color(165, 42, 42));
            } else {
                square.setFillColor(sf::Color::White);
            }
            square.setPosition((col * square_dims.first), (row * square_dims.second));
            m_window.draw(square);
        }
    }  

};

std::string ChessRender::map_name_to_file_name(std::string name, std::string color)
    /*
    This function maps the name of the piece to the file name of the piece.
    Arguments:
        name: The name of the piece.
        color: The color of the piece.
    Returns:
        The file name of the piece.
    */
{
    std::string file_name;
    if (color == "White") {
        file_name =  "View/images/w_" + name + ".png";
    } else {
        file_name = "View/images/b_" + name + ".png";
    }
    return file_name;
};

void ChessRender::draw_piece(const PieceInfo& piece_info, const BoardPixelMapper& board_pixel_mapper)
    /*
    This function draws the pieces. It is called by draw_chess().
    Arguments:
        name: The name of the piece.
        position: The position of the piece.
        color: The color of the piece.
        
    */
{
    std::string piece_file_name = map_name_to_file_name(piece_info.name, piece_info.color);
    sf::Texture piece_texture;
    sf::Sprite piece_sprite;
    if(!piece_texture.loadFromFile(piece_file_name)) {
        //std::cout << "Error loading piece texture" << std::endl;
    }
    //Need to fix this.
    std::pair<unsigned int, unsigned int> pixel_coords = board_pixel_mapper.transform_square_coords_to_pixel(piece_info.position);
    piece_sprite.setTexture(piece_texture);
    piece_sprite.setPosition(pixel_coords.first, pixel_coords.second);
    m_window.draw(piece_sprite);
};

void ChessRender::draw_chess(const std::vector<PieceInfo>& piece_info_list, const BoardPixelMapper& board_pixel_mapper)
    /*
    This function draws the chess game.
    */
{
    m_window.clear();
    draw_board();
    for (const PieceInfo& piece_info : piece_info_list) {
        draw_piece(piece_info, board_pixel_mapper);
    }
    m_window.display();
};

bool ChessRender::is_open() const
    /*
    This function returns whether the window is open.
    */
{
    return m_window.isOpen();
};

std::pair<int,int> ChessRender::get_window_dims() const
    /*
    This function returns the dimensions of the window.
    */
{
    return m_board_size;
};

std::pair<int,int> ChessRender::get_board_dims() const
    /*
    This function returns the dimensions of the square.
    */
{
    //For now board size is the same as window size.
    return m_board_size;
};