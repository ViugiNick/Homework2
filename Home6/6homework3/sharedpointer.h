#pragma once

template <typename T>
struct Note
{
    T* val;
    int cnt;

    ~Note()
    {
        delete val;
    }
};

template <typename T>
class SharedPointer
{
    public:
        SharedPointer();
        ~SharedPointer();

        SharedPointer(T *ptr);
        SharedPointer(SharedPointer &ptr);
        SharedPointer &operator= (SharedPointer &ptr);

        T* getVal();
        int getCnt();

    private:
        Note<T>* main;
};

template<typename T>
SharedPointer<T>::SharedPointer()
{
    main = new Note<T>;
    main->val = nullptr;
    main->cnt = 0;
}
template <typename T>
SharedPointer<T>::~SharedPointer()
{
    main->cnt--;

    if (main->cnt <= 0)
        delete main;
}



template<typename T>
SharedPointer<T>::SharedPointer(T *ptr)
{
    main = new Note<T>;
    main->val = ptr;
    main->cnt = 1;
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer &ptr)
{
    main = ptr.main;
    main->cnt++;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator= (SharedPointer &ptr)
{
    main->cnt--;

    if (main->cnt == 0)
        delete main;

    main = ptr.main;
    main->cnt++;
    return *this;
}

template <typename T>
T* SharedPointer<T>::getVal()
{
    return main->val;
}

template <typename T>
int SharedPointer<T>::getCnt()
{
    return main->cnt;
}
