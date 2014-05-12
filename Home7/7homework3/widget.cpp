
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <time.h>
#include "widget.h"
#include "ui_widget.h"
#include "tictactoe.h"
#include <iostream>

using namespace std;

GameWidget::GameWidget(QWidget *parent) :
       QWidget(parent),
       ui(new Ui::Widget),
       oldSize(0),
       state(one),
       size(0)
{
       ui->setupUi(this);

       qsrand(time(nullptr));

       generateButtons();

       ui->sizeSpinBox->findChild<QLineEdit *>()->setReadOnly(true);

       connect(ui->generateButton, &QPushButton::clicked
                       , this, &GameWidget::generateButtons);
}

void GameWidget::showMsgBox(const QString &text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

GameWidget::~GameWidget()
{
       delete ui;
}

void GameWidget::generateButtons()
{
    game.clearMap();
    //val.clear();
    field.clear();
    state = one;

    size = ui->sizeSpinBox->value();
    param = ui->paramSpinBox->value();
    param = min(param, size);
    ui->paramSpinBox->setValue(param);

    for (int i = 0; i < oldSize; i++) {
        for (int j = 0; j < oldSize; j++) {
            delete ui->gridLayout->itemAtPosition(i, j)->widget();
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            QPushButton *button = new QPushButton;
            field[button] = make_pair(i, j);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->gridLayout->addWidget(button, i, j);
            button->setText(" ");

            connect(button, &QPushButton::clicked, this, &GameWidget::processButtonClick);

       }
    }

    oldSize = size;
}

void GameWidget::processButtonClick()
{
    QPushButton *button = dynamic_cast<QPushButton *>(sender());

    if (state == one)
    {
        openButton(button, 'O');
        state = two;
        if(game.win('O', size, param))
        {
            showMsgBox("!!!You win (O)!!!");
        }
    }
    else if (state == two)
    {
        openButton(button, 'X');
        state = one;
        if(game.win('X', size, param))
        {
            showMsgBox("!!!You win (X)!!!");
        }
    }
}
void GameWidget::clearButton(QPushButton *button)
{
       button->setText("");
       button->setEnabled(true);
}

void GameWidget::openButton(QPushButton *button, char c)
{
        button->setEnabled(false);
        game.open(field[button].first, field[button].second, c);

        if(c == 'X')
            button->setText("X");
        else
            button->setText("O");
}
/*
bool GameWidget::win(char c)
{
    cerr << "CHECK" << c << endl;
    /*
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
    cerr << "!!!" << endl;

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
            cerr << i << " " << j << " " << flag << endl;
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
*/
