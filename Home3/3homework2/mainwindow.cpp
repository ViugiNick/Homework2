#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->operation->addItem("+");
    ui->operation->addItem("-");
    ui->operation->addItem("*");
    ui->operation->addItem("/");

    connect(ui->spinBox1, SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect(ui->spinBox2, SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect(ui->operation, SIGNAL(currentTextChanged(QString)), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    double result = tmp.calculate(ui->spinBox1->value(), ui->spinBox2->value(), ui->operation->currentText().toStdString()[0]);

    if(result == 100500)
        ui->equal->setText("NONE");
    else
        ui->equal->setText(QString::number(result));
}
