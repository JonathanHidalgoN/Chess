#include "Model/ChessModel.h"
#include "View/GamerRender.h"
#include "PieceInfo.h"
#include <iostream>

class ChessGame
{
    /*
    This class is used to run the chess game.
    */
private:
    ChessModel m_chess_model;
    ChessRender m_chess_render;
    
    std::vector<PieceInfo> get_piece_status()
    {
        if(m_chess_model.get_turn() == 0)
        {
            m_chess_model.start_game();
        }
        std::vector<int> alive_pieces_index = m_chess_model.get_alive_pieces_index();
        std::vector<PieceInfo> alive_pieces_info;
        for (int i = 0; i < alive_pieces_index.size(); i++)
        {
            alive_pieces_info.push_back(m_chess_model.get_piece_info(alive_pieces_index[i]));
        }
        return alive_pieces_info;
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
            if (!m_chess_render.render_game(event, get_piece_status()))
            {
                std::cout << "Game Over" << std::endl;
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