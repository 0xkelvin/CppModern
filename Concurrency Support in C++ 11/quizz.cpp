#include <iostream>
#include <thread>

void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    std::cout << "Even thread\n";
}


void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    std::cout << "Even thread\n";  
}

int main()
{
    for(int i=0;i<6;i++)
    {
        if(i%2 == 0)
        {
            std::thread t(threadFunctionEven);
            t.detach();
        }
        else
        {
            std::thread t(threadFunctionOdd);
        }
    }

    std::this_thread::sleep_for(std::chrono::microseconds(1));

    return 0;
}