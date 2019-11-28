#include <iostream>
#include <vector>
#include <string>

#include "Array/830_PositionsOfLargeGroups.cpp"


using namespace std;


int main()
{
    string S = "abcdddeeeeaabbbcd";
    vector<vector<int>> res = largeGroupPosition(S);
    for (auto& v : res) {
        for (auto& i : v)
            cout << i << " ";
        cout << endl;
    }
}

