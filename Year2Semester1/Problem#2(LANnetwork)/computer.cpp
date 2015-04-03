#include "computer.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Computer::Computer() : infected(false),  operationSystem(0)
{
	srand(time(NULL));
}

Computer::~Computer()
{
}

void Computer::infect()
{
	infected = true;
}

bool Computer::isInfected()
{
	return infected;
}

void Computer::setOperationSystem(int id)
{
	operationSystem = id;
}

void Computer::attack()
{
	int chance = rand() % 100 + 1;
	int  probability = 0;



	switch(operationSystem)
	{
		case 0:
			probability = 0;
			break;
		case 1:
			probability = 15;
			break;
		case 2:
			probability = 10000;
			break;
	}

	qDebug() << chance << "  " << probability << "(" << operationSystem << endl;

	if(chance <= probability)
	{
		this->infect();
	}
}
