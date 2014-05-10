#include "mainwindow.h"
#include <QApplication>
#include "testCounting.h"

int main(int argc, char *argv[])
{
    TestCounting countTester;
    QTest::qExec(&countTester);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
