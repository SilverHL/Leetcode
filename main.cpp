#include <iostream>
#include <vector>
#include <string>

#include "Array/999_AvailableCapturesForRook.cpp"

using namespace std;


int main()
{

    vector<int> ar1 = {28,6,22,8,44,17};
    vector<int> ar2 = {22,28,8,6};

    vector<int> res = relativeSortArray(ar1, ar2);
    for_each(begin(res), end(res), [](int n) { cout << n << endl;});
}

