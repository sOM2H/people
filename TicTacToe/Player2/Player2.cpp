#include"../TicTacToeMove.hpp"
#include<fstream>
#include<iostream>

Move process(std::string);

int main()
{
    Move playerMove = process("TicTacToe/Player2/field.txt");
    std::ofstream file;
    file.open("TicTacToe/Player2/move.txt");
    file << playerMove.r << ' ' << playerMove.c;
    file.close();
}

#include"AI.cpp"