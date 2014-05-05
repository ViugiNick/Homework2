#include "game.h"
#include <QMessageBox>
#include <ctime>
#include <ui_game.h>
#include <iostream>

const int constSizeOfField = 2;

Game::Game(QWidget *parent) :
    QWidget(parent),
    fieldSize(constSizeOfField),
    state(QVector<QVector<int>>(fieldSize, QVector<int>(fieldSize))),
    buttons(QVector<QPushButton*>(fieldSize * fieldSize)),
    numberOfOpened(0),
    turn(0)
    {
        ui->setupUi(this);
        randField(fieldSize);
        setupButtons();
    }

Game::Game(int fSize, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game),
    state(QVector<QVector<int>>(fSize, QVector<int>(fSize))),
    buttons(QVector<QPushButton*>(fSize * fSize)),
    fieldSize(fSize),
    numberOfOpened(0),
    turn(0)
    {
        ui->setupUi(this);
        randField(fSize);
        setupButtons();
    }

void Game::randField(int fSize)
{
    srand(time(NULL));
    int numberOfZeros = rand() % ((fSize*fSize) / 2);
    numberOfZeros *= 2;

    std::cerr << numberOfZeros << std::endl;

    for(int i = 0; i < fSize; i++)
    {
        for(int j = 0; j < fSize; j++)
        {
            if(i == fSize - 1 && j == fSize - 1 && numberOfZeros % 2 == 1)
            {
                value.push_back(0);
                state[i][j] = 0;
                std::cerr << 0;
                break;
            }
            if(i == fSize - 1 && j == fSize - 1 && numberOfZeros % 2 == 0)
            {
                value.push_back(1);
                state[i][j] = 1;
                std::cerr << 1;

                break;
            }

            if(rand() % 2 == 0)
            {
                if(numberOfZeros > 0)
                {
                    value.push_back(0);
                    state[i][j] = 0;
                    std::cerr << 0;
                    numberOfZeros--;
                }
                else
                {
                    value.push_back(1);
                    state[i][j] = 1;
                    std::cerr << 1;
                }
            }
            else
            {
                value.push_back(1);
                state[i][j] = 1;
                std::cerr << 1;
            }
        }
        std::cerr << std::endl;
    }
}

Game::~Game()
{
    delete ui;
}

void Game::showMsgBox(const QString &text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void Game::stateChanged(int pos)
{
     turn++;

     if (buttons[pos]->text().at(0) == ' ')
     {
        buttons[pos]->setText(value[pos] == 0 ? "0" : "1");
     }
     if(turn % 2 == 1)
     {
         oldPos = pos;
     }
     if(turn % 2 == 0)
     {
         //std::cerr << pos << " " << oldPos << std::endl;
         if(value[oldPos] != value[pos])
         {
            buttons[pos]->setText(" ");
            buttons[oldPos]->setText(" ");
         }
         else
         {
             buttons[pos]->setEnabled(false);
             buttons[oldPos]->setEnabled(false);
             numberOfOpened += 2;
             std::cerr << numberOfOpened << " " << fieldSize * fieldSize << std::endl;
             if(numberOfOpened == fieldSize*fieldSize)
             {
                 showMsgBox("You win!!!");
             }
         }
     }
}

void Game::setupButtons()
{
    qsm = new QSignalMapper(this);

    QGridLayout *mainLayout = new QGridLayout();
    for (int i = 0; i < fieldSize * fieldSize; i++)
    {
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;

        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % fieldSize, i / fieldSize);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(stateChanged(int)));

    setLayout(mainLayout);
}
