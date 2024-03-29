/* 
Memory Management exercises part 1: Pass data between functions without using move semantics
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//pass pack by pointer (old C++)
const int array_size = 1e6; //determine size of the random number array

vector<int> *RandomNumbers1()
{
    vector<int> *random_numbers = new vector<int>[array_size]; // allocate memory on the heap..
    for(int i=0; i<array_size; i++)
    {
        int b = rand();
        (*random_numbers).push_back(b); // ... and fill it with random numbers
    }
    return random_numbers; //return pointer to heap memory
}

//pass pack by reference (old C++)
void RandomNumbers2(vector<int> &random_numbers)
{
    random_numbers.resize(array_size);
    for(int i=0; i<array_size; i++)
    {
        random_numbers[i] = rand();
    }
}


int main()
{
    vector<int> *random_numbers_1 = RandomNumbers1();

    vector<int> random_numbers_2;
    RandomNumbers2(random_numbers_2);
}