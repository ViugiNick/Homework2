#pragma once

class Matrix
{
public:
	Matrix(int sizeOfMatrix);
	~Matrix();

	void newEdge(int vertex1, int vertex2);
	void markVertex(int vertex);
	bool answer();

private:
	void bfs(int startVertex);

	int size;

	bool * mark;
	int * used;
	bool ** map;
};
