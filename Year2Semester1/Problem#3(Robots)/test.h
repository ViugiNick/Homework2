#pragma once

#include <QtTest/QtTest>
#include <QDebug>
#include "matrix.h"

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:
	void simpleTestTrue()
	{
		Matrix temp(4);

		temp.newEdge(0, 1);
		temp.newEdge(1, 2);
		temp.newEdge(2, 3);

		temp.markVertex(0);
		temp.markVertex(2);

		QVERIFY(temp.answer());
	}

	void simpleTestFalse()
	{
		Matrix temp(4);

		temp.newEdge(0, 1);
		temp.newEdge(1, 2);
		temp.newEdge(2, 3);

		temp.markVertex(0);
		temp.markVertex(3);
		QVERIFY(!temp.answer());
	}

	void complexTestTrue()
	{
		Matrix temp(5);
		temp.newEdge(0, 1);
		temp.newEdge(1, 2);
		temp.newEdge(2, 3);
		temp.newEdge(2, 4);

		temp.markVertex(1);
		temp.markVertex(3);
		temp.markVertex(4);

		QVERIFY(temp.answer());
	}

	void complexTestFalse()
	{
		Matrix temp(5);

		temp.newEdge(0, 1);
		temp.newEdge(1, 2);
		temp.newEdge(2, 3);
		temp.newEdge(2, 4);

		temp.markVertex(0);
		temp.markVertex(3);
		temp.markVertex(4);

		QVERIFY(!temp.answer());
	}

};
