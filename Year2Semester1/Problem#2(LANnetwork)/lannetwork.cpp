#include "lannetwork.h"
#include <QVector>
#include <QDebug>

LanNetwork::LanNetwork(int size)
{
	srand(time(NULL));

	sizeOfNetwork = size;

	mapOfComputers = new Computer[sizeOfNetwork];
	for (int i = 0; i < sizeOfNetwork; i++)
	{
		int id = rand() % 3;
		mapOfComputers[i].setOperationSystem(id);
	}

	map = new bool * [sizeOfNetwork];
	for (int i = 0; i < sizeOfNetwork; i++)
	{
		map[i] = new bool[sizeOfNetwork];
		for (int j = 0; j < sizeOfNetwork; j++)
			map[i][j] = false;
	}
}

LanNetwork::~LanNetwork()
{
	delete[] mapOfComputers;
	for (int i = 0; i < sizeOfNetwork; ++i)
		delete[] map[i];
	delete[] map;
}

bool LanNetwork::ifComputerNumberInfected(int vertex)
{
	return mapOfComputers[vertex].isInfected();
}

void LanNetwork::addEdge(int vertex1, int vertex2)
{
	map[vertex1][vertex2] = true;
	map[vertex2][vertex1] = true;
}

void LanNetwork::infectComputerNumber(int vertex)
{
	mapOfComputers[vertex].infect();
}

bool LanNetwork::isEdge(int vertex1, int vertex2)
{
	return map[vertex1][vertex2];
}

void LanNetwork::makeTurn()
{
	QVector <int> infectedVertexes;
	infectedVertexes.clear();

	for (int i = 0; i < sizeOfNetwork; i++)
		if(mapOfComputers[i].isInfected())
		{
			infectedVertexes.push_back(i);
			qDebug() << i << endl;
		}
	for (int i = 0; i < infectedVertexes.size(); i++)
	{
		int currentVertex = infectedVertexes[i];

		for (int j = 0; j < sizeOfNetwork; ++j)
			if (map[currentVertex][j])
			{
				mapOfComputers[j].attack();
				qDebug() << "G to " << j << endl;
			}
	}
}
