#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include"TicTacToeField.hpp"

class TicTacToe
{
private:
    TicTacToeField field;
public:
    void run();
    char finished();
};

#endif