//
// Created by neojxwang(Íõ¾¸ìÓ) on 2020/3/10.
//

#include <iostream>
#include <vector>

using namespace std;

int matrixScore(vector<vector<int>>& A)
{
    for (auto &vec : A) {
        if (vec[0] == 0) {
            for (auto &i : vec)
                i ^= 1;
        }
    }

    const int r = A.size();
    const int l = A[0].size();

    int sum = r * (int)pow(2, l-1);

    for (int j = 1; j < l; j++) {
        int one_n = 0;
        int zero_n = 0;

        for (int i = 0; i < r; ++i) {
            if (A[i][j] == 0) {
                zero_n++;
            } else {
                one_n++;
            }
        }

        if (one_n > zero_n) {
            sum += one_n * (int)pow(2, l - j - 1);
        } else {
            sum += zero_n * (int)pow(2, l - j - 1);
        }
    }
    return sum;
}

