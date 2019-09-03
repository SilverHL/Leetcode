//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-03.
//
#include <vector>

using std::vector;
int fib(int N)
{
    if (N == 0)
        return 0;
    else if (N == 1 || N == 2)
        return 1;
    vector<int> res(N+1);
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i <= N; i++)
        res[i] = res[i-1] + res[i-2];

    return res[N];
}

