#include <iostream>
#include <vector>
#include <string>

#include "Array/999_AvailableCapturesForRook.cpp"
#include "Array/1002_FindCommonCharacters.cpp"

using namespace std;


int main()
{
    vector<string> vec1 = {"aa","aa","aa"};
    vector<string> res = commonChars(vec1);
    for_each(begin(res), end(res), [](string n) { cout << n << endl;});
}

