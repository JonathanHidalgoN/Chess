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
