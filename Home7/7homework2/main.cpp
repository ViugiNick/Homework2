#include <QCoreApplication>
#include "testvector.h"

int main(int argc, char *argv[])
{
    TestVector vectorTester;
    QTest::qExec(&vectorTester);

    QCoreApplication a(argc, argv);

    return a.exec();
}
