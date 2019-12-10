//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/6.
//
#include <vector>

using namespace std;

vector<int> prevPermOpt1(vector<int> &A)
{
    const int n = A.size();
    for (int i = n-1; i > 0; --i) {
        if (A[i-1] > A[i]) {
            for (int j = n-1; j >= i; --j)
                if (A[j] < A[i-1]) {
                    while (A[j] == A[j-1])
                        j--;
                    swap(A[j], A[i-1]);
                    return A;
                }
        }
    }
    return A;
}

