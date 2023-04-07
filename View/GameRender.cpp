#include"GamerRender.h"

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