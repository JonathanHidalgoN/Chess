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

PieceInfo ChessModel::get_piece_info(int index) const {
    /*
    This function is responsible for getting the information of a piece.
    Arguments:
        index: The index of the piece.
    Returns:
        A tuple containing the position, name and color of the piece.
    */
    PieceInfo piece_info;
    piece_info.position = m_pieces[index].get_position();
    piece_info.color = m_pieces[index].get_color();
    piece_info.name = m_pieces[index].get_name();
    piece_info.alive = m_pieces[index].get_is_alive();
}

std::vector<int> ChessModel::get_alive_pieces_index() const {
    /*
    This function is responsible for getting the index of the alive pieces.
    Returns:
        A vector containing the index of the alive pieces.
    */
    std::vector<int> alive_pieces_index;
    for (int i = 0; i < number_of_pieces; i++) {
        if (m_pieces[i].get_is_alive()) {
            alive_pieces_index.push_back(i);
        }
    }
    return alive_pieces_index;
}