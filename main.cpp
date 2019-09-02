#include <iostream>
#include <vector>
#include <string>

#include "Array/905_SortArrayByParity.cpp"
#include "Array/950_RevealCardsInIncreasingOrder.cpp"
using namespace std;
int main()
{
    vector<int> vec = {3,1,2,4};
    vector<int>res = sortArrayByParity(vec);
    for_each(res.begin(), res.end(), [&](int n) {cout << n << endl;});
}
