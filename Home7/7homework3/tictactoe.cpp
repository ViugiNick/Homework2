#include "tictactoe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe()
{
    val.clear();
}

void TicTacToe::clearMap()
{
    val.clear();
}

void TicTacToe::open(int x, int y, char c)
{
    val[make_pair(x, y)] = c;
}

bool TicTacToe::win(char c, int size, int param)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(val[make_pair(i, j)] == 'X')
                cerr << 'X';
            else
            {
                if(val[make_pair(i, j)] == 'O')
                    cerr << 'O';
                else
                    cerr << '.';
            }
        }
        cerr << endl;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j + param <= size; j++)
        {
            bool flag = true;

            for(int l = 0; l < param; l++)
            {
                if(val[make_pair(i, j + l)] != c)
                    flag = false;
            }
            cerr << "!" << i << " " << j << " " << flag << endl;
            if(flag)
                return true;
        }
    }

    for(int i = 0; i + param <= size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            bool flag = true;

            for(int l = 0; l < param; l++)
            {
                if(val[make_pair(i + l, j)] != c)
                    flag = false;
            }
            cerr << i << " " << j << " " << flag << endl;
            if(flag)
                return true;
        }
    }
    for(int i = 0; i + param <= size; i++)
    {
        for(int j = 0; j + param <= size; j++)
        {
            bool flag = true;

            for(int l = 0; l < param; l++)
            {
                if(val[make_pair(i + l, j + l)] != c)
                    flag = false;
            }
            cerr << i << " " << j << " " << flag << endl;
            if(flag)
                return true;
        }
    }
    for(int i = 0; i + param <= size; i++)
    {
        for(int j = param - 1; j < size; j++)
        {
            bool flag = true;

            for(int l = 0; l < param; l++)
            {
                if(val[make_pair(i + l, j - l)] != c)
                    flag = false;
            }
            cerr << i << " " << j << " " << flag << endl;
            if(flag)
                return true;
        }
    }
    return false;
}
