#include <iostream>
#include <vector>
#include <string>

#include "Array/717_1-bitAnd2-bitCharacters.cpp"
#include "Array/118_Pascal'sTriangle.cpp"

using namespace std;


int main()
{
    vector<vector<int>> res = generate(5);

    for (auto& v : res) {
        for (auto& i : v)
            cout << i << " ";
        cout << endl;
    }
}

