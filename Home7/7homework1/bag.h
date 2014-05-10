#pragma once
#include <QMap>
#include <QMapIterator>
#include <iostream>
#include <set>

using namespace std;

template <typename T>
class Bag
{
public:
    Bag(){}
    void addElement(const T& element);
    void deleteElement(const T& element);
    bool find(const T& element);
    int count(const T& element);
private:
    std::multiset <T> mainSet;
};

template <typename T>
void Bag<T>::addElement(const T &val)
{
    mainSet.insert(val);
}

template <typename T>
void Bag<T>::deleteElement(const T &val)
{
    if(mainSet.count(val) > 0)
    mainSet.erase(lower_bound(mainSet.begin(), mainSet.end(), val));
}

template <typename T>
bool Bag<T>::find(const T &val)
{
    return (mainSet.count(val) > 0);
}

template <typename T>
int Bag<T>::count(const T &val)
{
    return mainSet.count(val);
}
