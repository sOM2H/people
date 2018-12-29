#ifndef TIC_TAC_TOE_FIELD
#define TIC_TAC_TOE_FIELD

#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<exception>

class TicTacToeField
{
private:
    std::vector<std::vector<char> > field;
public:
    class OutOfBounds: public std::range_error
    {
    public:
        OutOfBounds();
        const char * what() const throw();
    };
    class RestrictedModifying: public std::logic_error
    {
    public:
        RestrictedModifying();
        const char * what() const throw();
    };
    TicTacToeField();
    char& at(int, int);
    std::vector<char>& operator[](const int);
    std::vector<char> operator[](const int) const;
    void loadFromFile(const std::string&);
    void saveToFile(const std::string&);
    void setAt(int, int, char);
    void print() const;
};

#endif