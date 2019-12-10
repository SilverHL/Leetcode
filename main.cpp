#include <iostream>
#include <vector>

#include "Array/1053_PreviousPermutationWithOneSwap.cc"

using namespace std;


int main()
{
    vector<int> A = {3,1,1,3};
    prevPermOpt1(A);

    for_each(begin(A), end(A), [](int n) { cout << n << endl;});
}

