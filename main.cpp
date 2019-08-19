#include <iostream>
#include <vector>

#include "234_PalindromeLinkedList.cc"
#include "88_MergeSortedArray.cpp"

using namespace std;
int main() {

    //Solution524 s;
    //524 LongestWordInDictWithDeleting
    //vector<string> vec = {"ale","apple","monkey","plea"};
    //std::cout << s.FindLongestWord("abpcplea", vec);
    //

    vector<int> vec = {1, 2, 3, 5, 0, 0, 0};
    vector<int> vec2 = {2, 3, 4};

    merge(vec, 4, vec2, 3);
    for_each(begin(vec), end(vec), [](int x) {cout << x << endl;});
}
