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


std::vector<Piece> SetUpPieces::place_initial_pieces() {

    /*
    This function is responsible for placing the pieces on the board.
    All the pieces are placed in the vector of pieces.
    Arguments:
        pieces: vector of pieces
    Returns:
        pieces: vector of pieces
    */
    std::vector<Piece> pieces;
    std::vector<Piece> pawns = place_initial_pawns();
    std::vector<Piece> rooks = place_initial_rooks();
    std::vector<Piece> knights = place_initial_horses();
    std::vector<Piece> bishops = place_initial_bishops();
    std::vector<Piece> queens = place_initial_queens();
    std::vector<Piece> kings = place_initial_kings();
    pieces.insert(pieces.end(), pawns.begin(), pawns.end());
    pieces.insert(pieces.end(), rooks.begin(), rooks.end());
    pieces.insert(pieces.end(), knights.begin(), knights.end());
    pieces.insert(pieces.end(), bishops.begin(), bishops.end());
    pieces.insert(pieces.end(), queens.begin(), queens.end());
    pieces.insert(pieces.end(), kings.begin(), kings.end());
    return pieces;

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

std::vector<Piece> SetUpPieces::place_initial_rooks() {
    /*
    This function is responsible for placing the rooks on the board.
    Returns:
        rooks: vector of rooks
    */
    std::vector<Piece> rooks;
    rooks.push_back(place_piece(std::make_pair(0, 7), "Rook", "White"));
    rooks.push_back(place_piece(std::make_pair(7, 7), "Rook", "White"));
    rooks.push_back(place_piece(std::make_pair(0, 0), "Rook", "Black"));
    rooks.push_back(place_piece(std::make_pair(7, 0), "Rook", "Black"));
    return rooks;
};

std::vector<Piece> SetUpPieces::place_initial_horses() {
    /*
    This function is responsible for placing the knights on the board.
    Returns:
        knights: vector of knights
    */
    std::vector<Piece> knights;
    knights.push_back(place_piece(std::make_pair(1, 7), "Horse", "White"));
    knights.push_back(place_piece(std::make_pair(6, 7), "Horse", "White"));
    knights.push_back(place_piece(std::make_pair(1, 0), "Horse", "Black"));
    knights.push_back(place_piece(std::make_pair(6, 0), "Horse", "Black"));
    return knights;
};

std::vector<Piece> SetUpPieces::place_initial_bishops() {
    /*
    This function is responsible for placing the bishops on the board.
    Returns:
        bishops: vector of bishops
    */
    std::vector<Piece> bishops;
    bishops.push_back(place_piece(std::make_pair(2, 7), "Bishop", "White"));
    bishops.push_back(place_piece(std::make_pair(5, 7), "Bishop", "White"));
    bishops.push_back(place_piece(std::make_pair(2, 0), "Bishop", "Black"));
    bishops.push_back(place_piece(std::make_pair(5, 0), "Bishop", "Black"));
    return bishops;
};

std::vector<Piece> SetUpPieces::place_initial_queens() {
    /*
    This function is responsible for placing the queens on the board.
    Returns:
        queens: vector of queens
    */
    std::vector<Piece> queens;
    queens.push_back(place_piece(std::make_pair(3, 7), "Queen", "White"));
    queens.push_back(place_piece(std::make_pair(3, 0), "Queen", "Black"));
    return queens;
};

std::vector<Piece> SetUpPieces::place_initial_kings() {
    /*
    This function is responsible for placing the kings on the board.
    Returns:
        kings: vector of kings
    */
    std::vector<Piece> kings;
    kings.push_back(place_piece(std::make_pair(4, 7), "King", "White"));
    kings.push_back(place_piece(std::make_pair(4, 0), "King", "Black"));
    return kings;
};

