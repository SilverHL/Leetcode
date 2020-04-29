//
// Created by neojxwang(Íõ¾¸ìÓ) on 2020/3/16.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> maxDepthAfterSplit(string seq)
{
    int n = seq.length();
    int A = 0;
    int B = 0;
    vector<int> res(n, 0);

    for (int i = 0; i < n; ++i) {
        char c = seq[i];
        if (c == '(') {
            if (A > B) {
                ++B;
                res[i] = 1;
            } else {
                ++A;
            }
        } else {
            if (A < B) {
                --B;
                res[i] = 1;
            } else {
                --A;
            }
        }
    }

    return res;
}
