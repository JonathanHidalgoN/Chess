#include"SetUpPieces.h"

SetUpPieces::SetUpPieces() {};

std::vector<Piece> SetUpPieces::place_initial_pieces(std::vector<Piece> &pieces) {

    /*
    This function is responsible for placing the pieces on the board.
    All the pieces are placed in the vector of pieces.
    Arguments:
        pieces: vector of pieces
    Returns:
        pieces: vector of pieces
    */

    place_initial_pawns();
    place_initial_rooks();
    place_initial_knights();
    place_initial_bishops();
    place_initial_queens();
    place_initial_kings();
};

