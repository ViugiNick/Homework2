#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
	Test networkTest;
	QTest::qExec(&networkTest);

	return 0;
}
