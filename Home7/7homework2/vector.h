#pragma once
#include <vector>
#include <iostream>

template <typename T, int sizeOfVector, T zero>
class Vector
{
public:
    /// Method, to construct vector from std::vector
    Vector(const std::vector<T> &otherVector);
    /// Method, to construct vector from another vector
    Vector(const Vector &otherVector);
    /// Method, which returns element on position 'pos'
    T takeValOnPos(int pos);
    /// Method, which write value 'val' on position 'pos'
    void makeValOnPos(int pos, const T& val);
    /// Method, to count sum
    Vector operator+(const Vector& otherVector);
    /// Method, to count difference
    Vector operator-(const Vector& otherVector);
    /// Method, to count scalar multiplaccation
    T operator*(const Vector& otherVector);
    bool operator==(const Vector& otherVector);
    bool isZero();

private:
    std::vector<T> mainVector;
};


template <typename T, int sizeOfVector, T zero>
Vector<T, sizeOfVector, zero>::Vector(const std::vector<T> &otherVector)
{
    mainVector.resize(sizeOfVector);
    for (int i = 0; i < sizeOfVector; i++)
    {
        //std::cerr << i << " " << otherVector[i] << std::endl;
        mainVector[i] = otherVector[i];
        //std::cerr << "Done" << std::endl;
    }
}

template <typename T, int sizeOfVector, T zero>
Vector<T, sizeOfVector, zero>::Vector(const Vector &otherVector)
{
    mainVector.resize(sizeOfVector);
    for (int i = 0; i < sizeOfVector; i++)
        mainVector[i] = otherVector.mainVector[i];
}

template <typename T, int sizeOfVector, T zero>
T Vector<T, sizeOfVector, zero>::takeValOnPos(int pos)
{
    std::cerr << "!!!" << pos << std::endl;
    return mainVector[pos];
}

template <typename T, int sizeOfVector, T zero>
void Vector<T, sizeOfVector, zero>::makeValOnPos(int pos,const T& val)
{
    mainVector[pos] = val;
}

template <typename T, int sizeOfVector, T zero>
Vector<T, sizeOfVector, zero> Vector<T, sizeOfVector, zero>::operator+(const Vector &otherVector)
{
    Vector tmp(mainVector);
    for (int i = 0; i < sizeOfVector; i++)
        tmp.makeValOnPos(i, mainVector[i] + otherVector.mainVector[i]);

    return tmp;
}

template <typename T, int sizeOfVector, T zero>
Vector<T, sizeOfVector, zero> Vector<T, sizeOfVector, zero>::operator-(const Vector &otherVector)
{
    Vector tmp(mainVector);
    for (int i = 0; i < sizeOfVector; i++)
        tmp.makeValOnPos(i, mainVector.at[i] - otherVector.mainVector[i]);

    return tmp;
}

template <typename T, int sizeOfVector, T zero>
T Vector<T, sizeOfVector, zero>::operator*(const Vector &otherVector)
{
    T answer = zero;
    for (int i = 0; i < sizeOfVector; ++i)
        answer += mainVector[i] * otherVector.mainVector[i];

    return answer;
}

template <typename T, int sizeOfVector, T zero>
bool Vector<T, sizeOfVector, zero>::operator==(const Vector &otherVector)
{
    for (int i = 0; i < sizeOfVector; i++)
        if (mainVector[i] != otherVector.mainVector[i])
            return false;

    return true;
}

template <typename T, int sizeOfVector, T zero>
bool Vector<T, sizeOfVector, zero>::isZero()
{
    for (int i = 0; i < sizeOfVector; i++)
        if (mainVector[i] != zero)
            return false;
    return true;
}

