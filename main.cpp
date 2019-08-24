#include <iostream>
#include <vector>

#include "209_MinimumSizeSubarraySum.cpp"

using namespace std;
int main() {

    //Solution524 s;
    //524 LongestWordInDictWithDeleting
    //vector<string> vec = {"ale","apple","monkey","plea"};
    //std::cout << s.FindLongestWord("abpcplea", vec);
    //

    vector<int> vec = {2,3,1,2,4,3};
    vector<int> vec1 = {1,2,3,4,5};
    cout << minimumSizeSubSum(11, vec1);

}
