#include"GamerRender.h"

ChessRender::ChessRender(
    const unsigned int width,
    const unsigned int height,
    const std::string title,
    const unsigned int frame_rate
)  
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
    m_window.create(sf::VideoMode(width, height), title);
    m_window.setFramerateLimit(frame_rate);
}