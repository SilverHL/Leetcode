//
// Created by neojxwang(Íõ¾¸ìÓ) on 2020/3/12.
//

#include <vector>
#include <string>

using namespace std;

int minDeletionSize(vector<string>& A)
{
    int res = 0;

    for (int j = 0; j < A[0].size(); ++j) {
        for (int i = 0; i < A.size()-1; ++i) {
            if (A[i][j] < A[i+1][j]) {
                res++;
                break;
            }
        }
    }

    return ans;

}

