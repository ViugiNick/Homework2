#include <iostream>
#include "exeptions.h"

using namespace std;

template <typename T>
class PriorityQueue
{
public:
    ~PriorityQueue()
    {
        deletePriorityQueue();
        delete head;
    }
    ///Method for adding element in the pririty queue
    void enqueue(T val, int prior)
    {
        QueueElement * currentElement = head->goToNext();

        if(currentElement == nullptr || currentElement->getPriority() < prior)
        {
            QueueElement * temp = new QueueElement();
            temp->makeValue(val, prior);
            temp->makeLink(currentElement);
            head->makeLink(temp);
        }
        else
        {
            while(currentElement != nullptr)
            {
                if(currentElement->getPriority() > prior && (currentElement->goToNext() == nullptr || currentElement->goToNext()->getPriority() < prior))
                {
                    QueueElement * temp = new QueueElement();
                    temp->makeValue(val, prior);
                    temp->makeLink(currentElement->goToNext());
                    currentElement->makeLink(temp);
                    break;
                }
                currentElement = currentElement->goToNext();
            }
        }
    }
    ///Method for deleting element in the pririty queue
    T dequeue()
    {
        if(head->goToNext() == nullptr)
        {
            throw(exeptions());
        }

        T result = head->goToNext()->getValue();
        QueueElement * temp = head->goToNext();
        head->makeLink(head->goToNext()->goToNext());
        delete temp;
        return result;
    }
    ///Method for deleting pririty queue
    void deletePriorityQueue()
    {
        while(head->goToNext() != nullptr)
        {
            QueueElement * temp = head->goToNext();
            head->goToNext()->makeLink(temp->goToNext());
            delete temp;
        }
    }
private:
    class QueueElement
    {
    public:
        QueueElement(T val, T prior):value(val),priority(prior){}
        QueueElement():value(0),priority(0){}

        T getValue()
        {
            return value;
        }

        T getPriority()
        {
            return priority;
        }

        void makeValue(T val, T prior)
        {
            this->value = val;
            this->priority = prior;
        }

        void makeLink(QueueElement * l)
        {
            next = l;
        }

        QueueElement * goToNext()
        {
            return next;
        }
    private:
        T value;
        int priority;
        QueueElement * next = nullptr;
    };
    QueueElement * head = new QueueElement(0, 0);
};


