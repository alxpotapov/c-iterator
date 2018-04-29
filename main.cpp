#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyArray
{
    T* arr;
    int _n;
public:
    class Iterator;
    MyArray(int n = 1) : _n(n)
    {
        arr = new T[n];
    }

    T& operator[] (const int& n)
    {
        if (n > 0 && n < _n)
            return arr[n];
        return arr[0];
    }

    Iterator begin() { return arr; }
    Iterator end() { return arr+_n; }


    class Iterator
    {
        T* cur;
    public:
        Iterator(T* first) : cur(first)
        {}

        T& operator+ (int n) { return *(cur + n); }
        T& operator- (int n) { return *(cur - n); }

        T& operator++ (int) { return *cur++; }
        T& operator-- (int) { return *cur--; }
        T& operator++ () { return *++cur; }
        T& operator-- () { return *--cur; }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }
        T& operator* () { return *cur; }
    };
};


int main()
{
    MyArray<string> arr(3);
    arr[0] = "str1";
    arr[1] = "str2";
    arr[2] = "str3";

    MyArray<string>::Iterator it = arr.begin();

    while (it != arr.end())
    {
        cout << *it << endl;
        it++;
    }

    for (MyArray<string>::Iterator it2 = arr.begin(); it2 != arr.end(); it2++)
    {
        cout << *it2 << endl;
    }

};
