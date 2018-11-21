#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<iostream>

Move process(std::string file)
{
    
    std::ifstream in;
    srand(time(nullptr));
    in.open(file);
    std::vector<std::vector<int> > field(3, std::vector<int>(3, -10));
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            in >> field[i][j];
        }
    }
    while(1)
    {
        int r = rand() % 3;
        int c = rand() % 3;
        if(field[r][c] == 0)
        {
            in.close();
            return {r, c};
        }
    }
}