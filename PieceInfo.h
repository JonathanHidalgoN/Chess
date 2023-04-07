#ifndef PIECEINFO_H
#define PIECEINFO_H

#include <string>
#include <utility>
struct PieceInfo {
    std::pair<int,int> position;
    std::string color;
    std::string name;
    bool alive;
};

#endif