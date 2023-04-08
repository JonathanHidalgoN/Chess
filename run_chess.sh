#!/bin/bash

# create build directory if it doesn't exist
if [ ! -d "build" ]; then
  mkdir build
fi

# compile the source code
g++ -c main.cpp -o build/main.o
g++ -c Model/ChessModel.cpp -o build/ChessModel.o
g++ -c Model/Moves/MovesStacker.cpp -o build/MovesStacker.o
g++ -c Model/Moves/MovesValidator.cpp -o build/MovesValidator.o
g++ -c Model/Pieces/BishopPiece.cpp -o build/BishopPiece.o
g++ -c Model/Pieces/HorsePiece.cpp -o build/HorsePiece.o
g++ -c Model/Pieces/KingPiece.cpp -o build/KingPiece.o
g++ -c Model/Pieces/PawnPiece.cpp -o build/PawnPiece.o
g++ -c Model/Pieces/Piece.cpp -o build/Piece.o
g++ -c Model/Pieces/QueenPiece.cpp -o build/QueenPiece.o
g++ -c Model/Pieces/RookPiece.cpp -o build/RookPiece.o
g++ -c Model/Setup/SetUpPieces.cpp -o build/SetUpPieces.o
g++ -c View/BoardPixelMapper.cpp -o build/BoardPixelMapper.o
g++ -c View/GameRender.cpp -o build/GameRender.o

# link the object files and create the executable
g++ build/main.o build/ChessModel.o build/MovesStacker.o build/MovesValidator.o \
build/BishopPiece.o build/HorsePiece.o build/KingPiece.o build/PawnPiece.o build/Piece.o \
build/QueenPiece.o build/RookPiece.o build/SetUpPieces.o build/BoardPixelMapper.o \
build/GameRender.o -lsfml-graphics -lsfml-window -lsfml-system -o build/chess_game

# run the game
./build/chess_game
