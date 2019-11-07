#include <iostream>
#include <vector>
#include <string>

#include "Array/697_DegreeOfAnArray.cpp"
#include "Array/900_RLEIterator.cpp"
#include "Array/39_CombinationSum.cpp"

using namespace std;


int main()
{
    vector<int> A{2,3,6,7};
    vector<vector<int>> res = combinationSum(A, 8);

    for (auto &v : res) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }
}

