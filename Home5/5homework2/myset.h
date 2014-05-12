#pragma once
#include <QList>
#include <iostream>
#include <myseterror.h>

template<typename T>
///Class MySet, based on QList
class MySet
{
    public:
        ///Method to return QList, on which based MySet
	QList<T> mySetToQList() const;
        ///Method to add value to MySet
    void add(const T &val);
        ///Method, which return size of MySet
	int sizeOfSet() const;
        ///Method, which sh
    bool find(const T &val) const;
        ///Method to delete element from set
    void deleteFromSet(const T &val);
        ///Method, which intersect two sets, and this<-result
	void intersectSet(const MySet<T> &firstSet, const MySet<T> &secondSet);
        ///Method, which union two sets, and this<-result
	void unionSet(const MySet<T> &firstSet, const MySet<T> &secondSet);
        ///Method to clear set
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
bool MySet <T>::find(const T &val) const
{
    return(mainList.count(val) > 0);
}

template<typename T>
int MySet <T>::sizeOfSet() const
{
    return mainList.count();
}


template<typename T>
void MySet <T>::add(const T &val)
{
    if (!find(val))
            mainList.append(val);
}

template<typename T>
void MySet <T>::deleteFromSet(const T &val)
{
    if (find(val))
        mainList.removeOne(val);
    else
    {
        throw SetErrors::NoSuchVal();
    }
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
