#pragma once
#include <QMap>
#include <QMapIterator>
#include <iostream>
#include <map>

using namespace std;

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
    std::map <T, int> mainMap;
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
    mainMap[val]++;
    sizeOfBag++;
}

template <typename T>
void Bag<T>::deleteElement(const T &val)
{
    if(mainMap.count(val) > 0)
    {
        mainMap[val]--;
        sizeOfBag--;
    }
}

template <typename T>
bool Bag<T>::find(const T &val)
{
    return (mainMap[val] > 0);
}

template <typename T>
int Bag<T>::count(const T &val)
{
    return mainMap[val];
}

template <typename T>
int Bag<T>::getSize()
{
    return sizeOfBag;
}
