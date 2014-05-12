#include "widget.h"
#include "testTic.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    GameWidget w;
    w.show();

    TestTic winTester;
    QTest::qExec(&winTester);

    return a.exec();
}
