#include"TicTacToeGame.hpp"

void TicTacToe::run()
{
    std::cout << finished();
    while(finished() == 'n')
    {
        field.saveToFile("Player1/field.txt");
        system("Player1/run");
        std::ifstream move;
        move.open("Player1/move.txt");
        int r, c;
        move >> r >> c;
        move.close();
        try
        {
            field.setAt(r, c, 1);
        }
        catch(TicTacToeField::OutOfBounds obex)
        {
            std::cout << "Player 1 caused exception: " << obex.what();
            return;
        }
        catch(TicTacToeField::RestrictedModifying rmex)
        {
            std::cout << "Player 1 caused exception: " << rmex.what();
            return;
        }
        field.print();
        char result = finished();
        if(result == 'd')
        {
            std::cout << "Draw\n";
            return;
        }
        if(result == 'w')
        {
            std::cout << "Player 1 won\n";
            return;
        }
        field.saveToFile("./Player2/field.txt");
        system("./Player2/run");
        move.open("./Player2/move.txt");
        move >> r >> c;
        move.close();
        try
        {
            field.setAt(r, c, 2);
        }
        catch(TicTacToeField::OutOfBounds obex)
        {
            std::cout << "Player 2 caused exception: " << obex.what();
            return;
        }
        catch(TicTacToeField::RestrictedModifying rmex)
        {
            std::cout << "Player 2 caused exception: " << rmex.what();
            return;
        }
        field.print();
        result = finished();
        if(result == 'd')
        {
            std::cout << "Draw\n";
            return;
        }
        if(result == 'w')
        {
            std::cout << "Player 2 won\n";
            return;
        }
    }
    std::cout << "Draw\n";
}

char TicTacToe::finished()
{
    for(int i = 0; i < 3; ++i)
    {
        if((field[i][0] != 0 && field[i][0] == field[i][1] && field[i][1] == field[i][2])
            || (field[0][i] != 0 && field[0][i] == field[1][i] && field[1][i] == field[2][i]))
            return 'w';                 // some player won
    }
    if(field[0][0] != 0 && field[0][0] == field[1][1] && field[1][1] == field[2][2]) return 'w';
    if(field[0][2] != 0 && field[0][2] == field[1][1] && field[1][1] == field[2][0]) return 'w';
    bool filled = true;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(field.at(i, j) == 0)
                filled = false;
    if(filled) return 'd';              // draw
    return 'n';                         // not finished
}