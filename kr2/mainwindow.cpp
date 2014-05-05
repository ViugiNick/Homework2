#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *mainLayout = new QGridLayout();

    Game *newGame = new Game(this);
    mainLayout->addWidget(newGame);
    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
