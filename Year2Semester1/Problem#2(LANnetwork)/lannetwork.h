#pragma once
#include "computer.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

class LanNetwork
{
public:
	LanNetwork(int size);
	~LanNetwork();

	void makeTurn();
	void addEdge(int vertex1, int vertex2);
	bool ifComputerNumberInfected(int vertex);
	void infectComputerNumber(int vertex);
	bool isEdge(int vertex1, int vertex2);
	Computer * mapOfComputers;

private:
	bool ** map;
	int sizeOfNetwork;
};
