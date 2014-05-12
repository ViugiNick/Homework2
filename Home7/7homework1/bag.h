#pragma once
#include <QMap>
#include <QMapIterator>
#include <iostream>
#include "bagerrors.h"

using namespace std;
using namespace BagErrors;

template <typename T>
///Class, based on multiset
class Bag
{
public:
    
    Bag();
    ~Bag();
    ///Add element to our muliset
    void addElement(const T& element);
    ///Delete element from out muliset
    void deleteElement(const T& element);
    ///Count size of bag
    int getSize();
    bool find(const T& element);
    ///Count number 'element' in multiset
    int count(const T& element);
private:
    QMap <T, int> mainMap;
    int sizeOfBag;
};

template <typename T>
Bag<T>::Bag() : sizeOfBag(0)
{
    mainMap.clear();
}

template <typename T>
Bag<T>::~Bag()
{
    mainMap.clear();
}

template <typename T>
void Bag<T>::addElement(const T &val)
{
    if(mainMap.contains(val))
        mainMap[val]++;
    else
        mainMap.insert(val, 1);

    sizeOfBag++;
}

template <typename T>
void Bag<T>::deleteElement(const T &val)
{
    if(find(val))
    {
        if(mainMap[val] == 1)
            mainMap.remove(val);
        else
            mainMap[val]--;

        sizeOfBag--;
    }
    else
    {
        BagErrors::NoSuchVal error;
        throw error;
    }
}

template <typename T>
bool Bag<T>::find(const T &val)
{
    return (mainMap.contains(val));
}

template <typename T>
int Bag<T>::count(const T &val)
{
    if(mainMap.contains(val))
        return mainMap[val];
}

template <typename T>
int Bag<T>::getSize()
{
    return sizeOfBag;
}
