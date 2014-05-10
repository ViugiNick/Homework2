#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arraystack.h"
#include "calculator.h"
#include "string"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signalMapper = new QSignalMapper(this);

    connect(ui->buttonSum, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonSum, "+");

    connect(ui->buttonNeg, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonNeg, "-");

    connect(ui->buttonMult, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonMult, "*");

    connect(ui->buttonDev, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonDev, "/");
    
    connect(ui->button0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button0, "0");

    connect(ui->button1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button1, "1");

    connect(ui->button2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button2, "2");

    connect(ui->button3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button3, "3");

    connect(ui->button4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button4, "4");

    connect(ui->button5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button5, "5");

    connect(ui->button6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button6, "6");

    connect(ui->button7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button7, "7");

    connect(ui->button8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button8, "8");

    connect(ui->button9, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button9, "9");

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(newDisplayString(QString)));
    connect(ui->buttonEqual, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(ui->buttonClear, SIGNAL(clicked()), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDisplayString(QString qStr)
{
    ui->lineEdit->setText(ui->lineEdit->text() + qStr);
}

void MainWindow::calculate()
{
    const int size = 100;
    std::string str;
    QString tmp = ui->lineEdit->text();
    str = tmp.toStdString();
    //std::cout << "!" << str << "!" << std::endl;
    int answer = calculateValue(str, str.size());
    //std::cout << "!" << str << "!" << std::endl;

    emit ui->lineEdit->setText(QString::number(answer));
}

void MainWindow::clear()
{
    emit ui->lineEdit->setText("");
}
