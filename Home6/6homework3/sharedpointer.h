#pragma once

template <typename T>
class SharedPointer
{
    public:
        SharedPointer();
        ~SharedPointer();

        ///Construct from pointer
        SharedPointer(T *ptr);
        ///Constructor copying
        SharedPointer(SharedPointer const &ptr);
        SharedPointer &operator= (SharedPointer const &ptr);
        ///Check, if no links on this memory, than deletessssss
        void dereference();

        ///Return pointer
        T* getVal();
        ///Number of links on this pointer
        int getCnt();

    private:
        struct Note
        {
            T* val;
            int cnt;

            ~Note()
            {
                delete val;
            }
            ///Empty constructor
            Note():val(nullptr), cnt(0) {}
            ///Constructor
            Note(T* val, int cnt):val(val), cnt(cnt) {}
        };
        Note* main;
};

template<typename T>
SharedPointer<T>::SharedPointer()
{
    main = new Note();
}
template <typename T>
SharedPointer<T>::~SharedPointer()
{
    main->cnt--;

    dereference();
}


template<typename T>
SharedPointer<T>::SharedPointer(T *ptr)
{
    main = new Note(ptr, 1);
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer const &ptr)
{
    main = ptr.main;
    main->cnt++;
}

template<typename T>
void SharedPointer<T>::dereference()
{
    if (main->cnt <= 0)
        delete main;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator= (SharedPointer const &ptr)
{
    main->cnt--;

    dereference();

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
