#include <iostream>
#include <vector>
#include <string>

#include "Two Pointers/30_SubstringOfConcatenationOfAllWords.cpp"
using namespace std;
int main()
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> vec = {"word","good", "best", "word"};
    vector<int> res = findSubstring(s, vec);
    for_each(res.begin(), res.end(), [&](int n) {cout << n << endl;});
}
