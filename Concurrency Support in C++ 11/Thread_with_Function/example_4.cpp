#include <iostream>

int main()
{
    // create lambdas
    int id = 0; // define an integer variable

    id++;
    auto f1 = [id]() { std::cout << "ID = " << id << std::endl;};

    id++;
    auto f2 = [&id]() { std::cout << "ID = " << id << std::endl;};

    auto f4 = [id]() mutable {std::cout << "ID = " << ++id << std::endl;};


    // execute lambdas
    f1();
    f2();
    f4();
}