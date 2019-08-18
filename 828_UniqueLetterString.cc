//
// Created by neojxwang(王靖煊) on 2019-08-07.
//

#include <string>
#include <functional>

using namespace std;

#define LL long long

int uniqueLetterString(string S) {
    const int mod = 1000000007;
    int n = S.length();
    LL ans = 0;
    vector<int> last(26, -1);

    vector<int> left(n, -1), right(n, n);

    for (int i = 0; i < n; i++)
    {
        left[i] = last[S[i] - 'A'];
        last[S[i] - 'A'] = i;
    }

    last = vector<int> (26, n);
    for (int i = n-1; i >= 0; i--)
    {
        right[i] = last[S[i] - 'A'];
        last[S[i] - 'A'] = i;
    }

    for (int i = 0; i < n; i++)
    {
       ans += (ans + (LL)(i - left[i]) * (right[i] - i)) % mod;
    }

    return ans;
}

