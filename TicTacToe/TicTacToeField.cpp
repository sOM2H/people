#include"TicTacToeField.hpp"

TicTacToeField::TicTacToeField(): field(3, std::vector<char>(3, 0)) {}

TicTacToeField::OutOfBounds::OutOfBounds(): std::range_error("if you see this, contact an administrator") {}

const char * TicTacToeField::OutOfBounds::what() const throw()
{
    return "You are trying to reach cell that does not belong to field\n";
}

TicTacToeField::RestrictedModifying::RestrictedModifying(): std::logic_error("if you see this, contact an administrator") {}

const char * TicTacToeField::RestrictedModifying::what() const throw()
{
    return "You are trying to modify cell that is not empty\n";
}

char& TicTacToeField::at(int r, int c)
{
    if(r >= 0 && r < 3 && c >= 0 && c < 3) return field[r][c];
    throw OutOfBounds();
}

std::vector<char>& TicTacToeField::operator[](const int pos)
{
    return field[pos];
}

std::vector<char> TicTacToeField::operator[](const int pos) const
{
    return field[pos];
}

void TicTacToeField::loadFromFile(const std::string& filename)
{
    std::ifstream file;
    file.open(filename);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int n;
            file >> n;
            field[i][j] = static_cast<char>(n);
        }
    }
    file.close();
}

void TicTacToeField::saveToFile(const std::string& filename)
{
    std::ofstream file;
    file.open(filename);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            file << static_cast<int>(field[i][j]) << ' ';
        }
        file << std::endl;
    }
    file.close();
}

void TicTacToeField::setAt(int r, int c, char player)
{
    try
    {
        at(r, c);
    }
    catch(OutOfBounds ex)
    {
        throw ex;
    }
    char& item = at(r, c);
    if(item != 0)
    {
        throw RestrictedModifying();
    }
    item = player;
}

void TicTacToeField::print() const
{
    std::cout << "------Printing field------\n";
    for(auto v : field)
    {
        for(auto x : v) std::cout << static_cast<int>(x) << ' ';
        std::cout << '\n';
    }
}