#pragma once

class Computer
{
public:
	Computer();
	~Computer();
	void infect();
	bool isInfected();

	void attack();
	void setOperationSystem(int id);

private:
	bool infected;
	int operationSystem;
};
