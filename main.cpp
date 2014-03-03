#include "linkedlist.h"
#include "listwitharray.h"
#include <iostream>

int main()
{
    LinkedList * temp1 = new LinkedList();

    temp1->insert(0, 9);
    temp1->insert(0, 3);
    temp1->insert(0, 2);

    printf("%d\n", temp1->length());
    temp1->printList();
    printf("\n\n");

    temp1->deleteList();
    delete temp1;

    //*************************

    ListWithArray * temp2 = new ListWithArray();

    temp2->insert(0, 9);
    temp2->insert(0, 3);
    temp2->insert(0, 2);

    printf("%d\n", temp2->length());
    temp2->printList();
    printf("\n\n");

    temp2->deleteList();
    delete temp2;

    return 0;
}
