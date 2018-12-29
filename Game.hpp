#ifndef GAME_HPP
#define GAME_HPP
#include"json.hpp"
#include<fstream>

template<typename T>
class Game
{
private:
protected:
    T field;
public:
    void run()
    {
        nlohmann::json allMoves(nlohmann::json::value_t::array);
        nlohmann::json winner(nlohmann::json::value_t::object);
        while(finished() == 'n')
        {
            field.saveToFile("./TicTacToe/Player1/field.txt");
            system("./TicTacToe/Player1/run");
            std::ifstream move;
            move.open("./TicTacToe/Player1/move.txt");
            int r, c;
            move >> r >> c;
            move.close();
            nlohmann::json jsonMove = {r, c};
            allMoves.push_back(jsonMove);
    //        try
            {
                field.setAt(r, c, 1);
            }
            /*catch(T::OutOfBounds obex)
            {
                std::cerr << "Player 1 caused exception: " << obex.what();
                return;
            }
            catch(T::RestrictedModifying rmex)
            {
                std::cerr << "Player 1 caused exception: " << rmex.what();
                return;
            }*/
            char fin = finished();
            if(fin == 'w')
            {
                winner = {1};
                break;
            }
            if(fin == 'd')
            {
                winner = {0};
                break;
            }
            field.saveToFile("./TicTacToe/Player2/field.txt");
            system("./TicTacToe/Player2/run");
            move.open("./TicTacToe/Player2/move.txt");
            move >> r >> c;
            move.close();
            jsonMove = {r, c};
            allMoves.push_back(jsonMove);
            //try
            {
                field.setAt(r, c, 2);
            }
            /*catch(T::OutOfBounds obex)
            {
                std::cerr << "Player 2 caused exception: " << obex.what();
                return;
            }
            catch(T::RestrictedModifying rmex)
            {
                std::cerr << "Player 2 caused exception: " << rmex.what();
                return;
            }*/
            fin = finished();
            if(fin == 'w')
            {
                winner = {2};
                break;
            }
            if(fin == 'd')
            {
                winner = {0};
                break;
            }
        }
        std::ofstream movesList;
        movesList.open("moves.json");
        movesList << allMoves.dump();
        movesList << winner.dump();
        movesList.close();
    }
    virtual char finished() const = 0;
};

#endif