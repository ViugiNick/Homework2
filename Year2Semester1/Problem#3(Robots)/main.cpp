#include "test.h"

int main()
{
	Test tst;
	QTest::qExec(&tst);

	return 0;
}
