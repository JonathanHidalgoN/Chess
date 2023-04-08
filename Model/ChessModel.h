#ifndef CHESSMODEL_H
#define CHESSMODEL_H

#include "../PieceInfo.h"
#include "Moves/MovesValidator.h"
#include "Setup/SetUpPieces.h"

class ChessModel {

    /*
    This class is responsible for the game logic.
    */

private:
    int m_turn{0};
    int number_of_pieces{32};
    std::vector<Piece> m_pieces;
    void set_up_pieces(SetUpPieces &setup);

public:
    ChessModel();
    void start_game();
    void set_turn(int turn);
    int get_turn() const;
    std::vector<int> get_alive_pieces_index() const;
    PieceInfo get_piece_info(int index) const;

};

#endif