#include <vector>

#ifndef MOVESSTACKER_H
#define MOVESSTACKER_H

class MovesStacker {
    /*
    This class is responsible for stacking moves in a direction.
    Arguments:
        piece_position: position of the piece
    */

private:
    std::pair<int,int> m_piece_position;
    std::pair<int,int> stack_move_in_direction(int direction, int number_of_moves) const;

public:
    MovesStacker(std::pair<int,int> piece_position);
    std::pair<int,int> stack_move_coords(int x_moves, int y_moves) const;
    std::vector<std::pair<int,int>> stack_moves_in_direction(int direction, int number_of_moves, 
    std::vector<std::pair<int,int>> possible_moves = {}) const;
    std::pair<int,int> get_piece_position() const;
    void change_piece(std::pair<int,int> new_position);
};

#endif