//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-05.
//
int maxSumTwoNoOverlap(vector<int>& A, int L, int M)
{
    int n = A.size();
    vector<int>& pre_sum = A;

    for (int i = 1; i < n; ++i) {
        pre_sum[i] = pre_sum[i-1] + A[i];
    }

    int res = pre_sum[L + M - 1];
    int max_l = pre_sum[l-1];
    int max_m = pre_sum[m-1];
    for (int i = L + M; i < n; ++i) {
        max_l = max(max_l, pre_sum[i - M] - pre_sum[i - M - L]);
        max_m = max(max_m, pre_sum[i - L] - pre_sum[i - M - L]);
        res = max(res, max(max_l + pre_sum[i] - pre_sum[i-M], max_m + pre_sum[i] - pre_sum[i-L]));
    }

    return res;


}

