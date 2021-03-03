#include <string>

using namespace std;

string reverseOnlyLetters(string S) {
    if (S.empty())
        return "";
    
    int n = S.length();
    int i = 0;
    int j = n-1;

    string res;

    while (j >= 0 && i < n) {
        if (!isalpha(S[j]))
            --j;

        if (isalpha(S[i])) {
            res += S[j];
            --j;
            ++i;
        } else {
            res += S[i];
            i++;
        }
    }

    while (i < n) 
        res += S[i++];

    return res;

}