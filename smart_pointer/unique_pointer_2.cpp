#include <iostream>
#include <memory>
#include <string>

class MyClass
{
private:
    /* data */
    std::string _text;
public:
    MyClass(/* args */);
    MyClass(std::string text) {_text = text;}
    ~MyClass();
    void setText(std::string text) {_text = text;}
};

MyClass::MyClass(/* args */)
{
}

MyClass::~MyClass()
{
    std::cout << _text << "destroyed" << std::endl;
}

int main()
{
    // create unique pointer to proprietary class
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));

    // call member function using arrow
    myClass1->setText("maiquocviet test1");

    // use the dereference operator *
    *myClass1 = *myClass2;

    // use the .get() function to retrieve a raw pointer to the object()
    std::cout << "Objects have stack addresss " << myClass1.get() << " and " << myClass2.get() << std::endl;
}