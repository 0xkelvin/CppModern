#include <iostream>

using namespace std;

// this class for managing a template-based heap resource implements move semantics

template <class T>
class MyClass
{
    T *data = nullptr;
public:
    MyClass() {}

    // move constructor
    MyClass(MyClass &&other)
    {
        data = other.data;
        other.data = nullptr;
    }

    // move assignment operator
    MyClass &operator=(MyClass &&other)
    {
        if(this != &other)
        {
            if (data)
            {
                delete data;
            }
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // copy constructor
    MyClass(const MyClass &);

    // copy assignment operator
    MyClass &operator=(const MyClass &);

    ~MyClass()
    {
        if(data)
        {
            delete data;
        }
    }
};


int main()
{
    MyClass<double> h1; // regular constructor 
    MyClass<double> h3 = move(h1); // move constructor (rvalue as input)
    return 0;
}