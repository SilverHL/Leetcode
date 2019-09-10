#include <iostream>
#include <vector>
#include <string>

#include "Array/969_PancakeSorting.cpp"

using namespace std;


int main()
{
    vector<int> vec = {3,2,4,1};
    vector<int> res = pancakeSort(vec);
    for_each(begin(res), end(res), [](int n) { cout << n << endl;});
}

