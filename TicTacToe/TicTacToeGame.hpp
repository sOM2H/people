#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include"TicTacToeField.hpp"
#include"../Game.hpp"

class TicTacToe: public Game<TicTacToeField>
{
private:
    //TicTacToeField field;
public:
    //void run();
    char finished() const;
};

#endif
