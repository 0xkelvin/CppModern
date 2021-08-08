#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};

int main()
{
    // create thread
    std::thread t1( Vehicle()) );

    std::thread t2 = std::thread( Vehicle() );

    std::thread t3{ Vehicle() };

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}