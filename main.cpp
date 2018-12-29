#include"TicTacToe/TicTacToeGame.hpp"

int main()
{
    std::ifstream in;
    in.open("ChosenGame.txt");
    int choice;
    in >> choice;
    switch(choice)
    {
        case 0:
        {
            Game<TicTacToeField>* game = new TicTacToe();
            game->run();
            break;
        }
        /*case 1:
            game = new SeaBattle();
            break;*/
        default:
            std::cerr << "Incorrect game choice\n";
            return 1;
    }
}