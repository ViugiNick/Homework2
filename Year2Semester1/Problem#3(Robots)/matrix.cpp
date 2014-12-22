#include <QQueue>
#include "matrix.h"

Matrix::Matrix(int size) : size(size)
{
	mark = new bool[size];
	used = new int[size];
	map = new bool * [size];

	for (int i = 0; i < size; ++i)
	{
		mark[i] = false;
		used[i] = 1;

		map[i] = new bool[size];
		for (int j = 0; j < size; ++j)
			map[i][j] = false;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; ++i)
		delete[] map[i];

	delete[] map;
	delete[] used;
	delete[] mark;
}

void Matrix::newEdge(int vertex1, int vertex2)
{
	map[vertex1][vertex2] = true;
	map[vertex2][vertex1] = true;
}

void Matrix::markVertex(int vertex)
{
	mark[vertex] = true;
}

void Matrix::bfs(int startVertex)
{
	QQueue<int> queueForBFS;
	queueForBFS.push_back(startVertex);

	used[startVertex] = 2;

	while(!queueForBFS.isEmpty())
	{
		int top = queueForBFS.front();
		queueForBFS.pop_front();

		for (int i = 0; i < size; i++)
		{
			if (map[top][i])
			{
				for (int j = 0; j < size; ++j)
				{
					if (map[i][j] && (used[j] == 1))
					{
						queueForBFS.push_back(j);
						used[j] = 2;
					}
				}
			}
		}
	}
}

bool Matrix::answer()
{
	bfs(0);

	int vertex1 = 0;
	int vertex2 = 0;

	for (int i = 0; i < size; ++i)
	{
		if (mark[i] && used[i] == 1)
			vertex1++;
		if (mark[i] && used[i] != 1)
			vertex2++;
	}

	return (vertex1 != 1 && vertex2 != 1) ;
}
