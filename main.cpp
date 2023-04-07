#include "Model/ChessModel.h"
#include "View/GamerRender.h"

class ChessGame
{
    /*
    This class is used to run the chess game.
    */
private:
    ChessModel m_chess_model;
    ChessRender m_chess_render;
    void start_game()
    {
        /*
        This function is responsible for starting the game.
        */
        m_chess_model.start_game();
        //function to parse the board and draw the pieces.
    }

public:
    ChessGame(): m_chess_model(), m_chess_render() {};
    
    void run()
    {
        /*
        This function runs the game.
        */
        while (m_chess_render.is_open())
        {
            sf::Event event;
            if (!m_chess_render.render_game(event))
            {
                break;
            }
        }
    }
};

int main() {
    ChessGame chess_game;
    chess_game.run();
    return 0;
}