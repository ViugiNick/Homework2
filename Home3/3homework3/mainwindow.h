#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    ///Method to show new operand on display
    void newDisplayString(QString qStr);
    ///Method to count exprassion, which is on display
    void calculate();
    ///Method to clear the display
    void clear();
private:
    QSignalMapper * signalMapper;
    Ui::MainWindow *ui;
};
