#include <QCoreApplication>
#include "singlylinkedlist.h"
#include "doublylinkedlist.h"
#include "testDoubly.h"
#include "testSingly.h"
#include <iostream>

using namespace std;

int main()
{
    TestSinglyLinkedLists singlyTester;
    QTest::qExec(&singlyTester);

    cout << "Singly Linked List" << endl;

    SinglyLinkedList *temp1 = new SinglyLinkedList();

    temp1->insertToPosition(0, 3);
    temp1->insertToPosition(1, 9);
    temp1->insertToPosition(0, 2);

    temp1->printList();
    cout << temp1->findInList(3) << endl;
    cout << temp1->findInList(1) << endl;
    delete temp1;

    cout << "Doubly Linked List" << endl;

    TestDoublyLinkedLists doublyTester;
    QTest::qExec(&doublyTester);

    DoublyLinkedList *temp2 = new DoublyLinkedList();

    cout << "!" << endl;
    temp2->insertToPosition(0, 3);
    temp2->insertToPosition(1, 9);
    temp2->insertToPosition(0, 2);

    temp2->printList();
    cout << temp2->findInList(3) << endl;
    cout << temp2->findInList(1) << endl;
    delete temp2;

    return 0;
}

