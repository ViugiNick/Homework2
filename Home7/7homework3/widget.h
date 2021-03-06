
#pragma once

#include <QWidget>
#include <QMap>
#include <QPushButton>
#include <map>
#include "tictactoe.h"

namespace Ui {
class Widget;
}

class GameWidget : public QWidget
{
       Q_OBJECT

public:
       explicit GameWidget(QWidget *parent = 0);
       ~GameWidget();

private slots:
       void generateButtons();
       void processButtonClick();

private:
       ///Delete text fro buttton
       void clearButton(QPushButton *button);
       ///Makes a turm (set text on button)
       void openButton(QPushButton *button, char c);
       ///Show you message, that you wins
       void showMsgBox(const QString &text);
       Ui::Widget *ui;
       int oldSize;

       TicTacToe game;
       enum State {
               none,
               one,
               two
       };

       State state;

       ///From button, gives  you x and y position of button
       std::map <QPushButton *, std::pair<int, int>> field;

       ///Numbers of buttons in line, need to win
       int param;
       int size;
};
