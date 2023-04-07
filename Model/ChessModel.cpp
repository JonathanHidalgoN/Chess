#include"ChessModel.h"

ChessModel::ChessModel(): m_pieces(number_of_pieces) {};

void ChessModel::set_up_pieces(SetUpPieces &setup) {
    /*
    This function is responsible for setting up the pieces on the board.
    Arguments:
        setup: object of the class SetUpPieces
    */
    m_pieces = setup.place_initial_pieces();
}

void ChessModel::start_game() {
    /*
    This function is responsible for starting the game.
    */
    SetUpPieces setup;
    set_up_pieces(setup);
}

void ChessModel::set_turn(int turn) {
    /*
    This function is responsible for setting the turn.
    Arguments:
        turn: The turn of the game.
    */
    m_turn = turn;
}