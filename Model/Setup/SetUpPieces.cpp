#include"SetUpPieces.h"

SetUpPieces::SetUpPieces() {};

Piece SetUpPieces::place_piece(std::pair<int,int> position, std::string name, std::string color) {
    /*
    This function is responsible for placing a piece on the board.
    Arguments:
        position: position of the piece
        name: name of the piece
        color: color of the piece
    Returns:
        piece: piece
    */
   if (name == "Pawn")
        return PawnPiece(position, color, true);
    else if (name == "Rook")
        return RookPiece(position, color, true);
    else if (name == "Horse")
        return HorsePiece(position, color, true);
    else if (name == "Bishop")
        return BishopPiece(position, color, true);
    else if (name == "Queen")
        return QueenPiece(position, color, true);
    else if (name == "King")
        return KingPiece(position, color, true);
};


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

std::vector<Piece> SetUpPieces::place_initial_pawns() {
    /*
    This function is responsible for placing the pawns on the board.
    Returns:
        pawns: vector of pawns
    */
    std::vector<Piece> pawns;
    for (int i = 0; i < 8; i++) {
        pawns.push_back(place_piece(std::make_pair(i, 6), "Pawn", "White"));
        pawns.push_back(place_piece(std::make_pair(i, 1), "Pawn", "Black"));
    }
    return pawns;
};

