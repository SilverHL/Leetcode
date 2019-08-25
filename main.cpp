#include <iostream>
#include <vector>

#include "209_MinimumSizeSubarraySum.cpp"
#include "845_LongestMountainInArray.cpp"
#include "923_3SumWithMultiplicity.cpp"

using namespace std;
int main() {

    //Solution524 s;
    //524 LongestWordInDictWithDeleting
    //vector<string> vec = {"ale","apple","monkey","plea"};
    //std::cout << s.FindLongestWord("abpcplea", vec);
    //

    vector<int> vec = {2,1,4,7,3,2,5};
    vector<int> vec1 = {1,1,2,2,3,3,4,4,5,5};

    cout << threeSumMulti(vec1, 8);

}
