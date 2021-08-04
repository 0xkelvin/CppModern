#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    std::cout << "Finished work in thread\n";
}


int main()
{
    std::thread t(threadFunction);

    std::this_thread::sleep_for(std::chrono::microseconds(50));
    std::cout << "Finished work in main\n";

    t.join();

    return 0;
}