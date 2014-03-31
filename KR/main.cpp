#include "priorityQueue.h"
#include <iostream>

using namespace std;

int main()
{
    PriorityQueue<int> *temp = new PriorityQueue<int>();

    temp->enqueue(1, 3);
    temp->enqueue(2, 9);
    temp->enqueue(3, 2);

    cout << temp->dequeue() << endl;
    cout << temp->dequeue() << endl;
    cout << temp->dequeue() << endl;
    cout << temp->dequeue() << endl;
    delete temp;

    return 0;
}
