#pragma once
#include <QList>
#include <iostream>

template<typename T>
class MySet
{
    public:
        QList<T> mySetToQList() const;
        void add(T val);
        int sizeOfSet() const;
        bool find(T val) const;
        void deleteFromSet(T val);
        void intersectSet(const MySet<T> &firstSet, const MySet<T> &secondSet);
        void unionSet(const MySet<T> &firstSet, const MySet<T> &secondSet);
        void clearSet();
    private:
        QList <T> mainList;
};

template<typename T>
QList<T> MySet<T>::mySetToQList() const
{
    return mainList;
}

template<typename T>
bool MySet <T>::find(T val) const
{
    return(mainList.count(val) > 0);
}

template<typename T>
int MySet <T>::sizeOfSet() const
{
    return mainList.count();
}


template<typename T>
void MySet <T>::add(T val)
{
    if (!find(val))
            mainList.append(val);
}

template<typename T>
void MySet <T>::deleteFromSet(T val)
{
    if (find(val))
        mainList.removeOne(val);
}

template<typename T>
void MySet <T>::intersectSet(const MySet<T> &firstSet, const MySet<T> &secondSet)
{
    QList <T> tmp = firstSet.mySetToQList();

    for (const T &currentElement : tmp)
        if(secondSet.find(currentElement))
            add(currentElement);
}

template<typename T>
void MySet <T>::unionSet(const MySet<T> &firstSet, const MySet<T> &secondSet)
{
    QList <T> tmp1 = firstSet.mySetToQList();
    QList <T> tmp2 = secondSet.mySetToQList();

    for (const T &currentElement : tmp1)
        add(currentElement);
    for (const T &currentElement : tmp2)
        add(currentElement);
}

template<typename T>
void MySet <T>::clearSet()
{
    mainList.clear();
}
