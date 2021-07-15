/* 
Memory Management exercises part 2: Use move semantics implicitly as part of the STL
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int array_size = 1e6;
vector<int> RandomNumbers3()
{
    vector<int> random_numbers;
    random_numbers.resize(array_size);
    for(int i=0; i<array_size; i++)
    {
        random_numbers[i] = rand();
    }
    return random_numbers; // return-by-value of the STL vector
}

int main()
{
    vector<int> random_numbers_3 = RandomNumbers3(); // will not copy the vector but use move semantics "under the hood"
    
}