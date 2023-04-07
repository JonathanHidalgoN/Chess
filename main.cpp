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
public:
    ChessGame(): m_chess_model(), m_chess_render() {};
    
    void run()
    {
        /*
        This function runs the game.
        */
        m_chess_render.draw_chess();
    }

};

int main() {
    ChessGame chess_game;
    chess_game.run();
    return 0;
}