#pragma once
#include <QString>
#include <map>

class TicTacToe
{
    public:
        TicTacToe();
        ///Open button (x, y) and write c on it
        void open(int x, int y, char c);
        void clearMap();

        ///Check, if player 'c' wins
        bool win(char c, int size, int param);
    private:

        ///From x and y position gives you letter in this buttons
        std::map <std::pair<int, int>, char> val;
};
