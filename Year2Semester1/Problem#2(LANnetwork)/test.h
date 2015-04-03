#pragma once

#include <QtTest/QtTest>
#include "lannetwork.h"
#include "QDebug"

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:

	void nonConnected()
	{
		int tempSize = 4;
		LanNetwork temp(tempSize);

		temp.infectComputerNumber(0);
		temp.infectComputerNumber(2);

		temp.makeTurn();

		for(int i = 0; i < tempSize; i++)
			qDebug() << temp.ifComputerNumberInfected(i) << endl;

		QVERIFY(temp.ifComputerNumberInfected(0) && !temp.ifComputerNumberInfected(1) && temp.ifComputerNumberInfected(2) && !temp.ifComputerNumberInfected(3));
	}

	void appleSUXXXXXXX()
	{
		int tempSize = 5;
		LanNetwork temp(tempSize);

		temp.infectComputerNumber(0);

		temp.addEdge(0, 1);
		temp.addEdge(1, 3);
		temp.addEdge(1, 2);
		temp.addEdge(1, 4);

		temp.mapOfComputers[1].setOperationSystem(2);
		temp.mapOfComputers[3].setOperationSystem(2);
		temp.mapOfComputers[4].setOperationSystem(0);
		temp.mapOfComputers[2].setOperationSystem(1);

		temp.makeTurn();
		temp.makeTurn();

		for(int i = 0; i < tempSize; i++)
			qDebug() << i << ") " << temp.ifComputerNumberInfected(i) << endl;

		QVERIFY(temp.ifComputerNumberInfected(0) && temp.ifComputerNumberInfected(1) && temp.ifComputerNumberInfected(3));
	}

};
