//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-05.
//

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
{
    if (A.empty())
        return {};
    int mp[10005] = {0};
    int sum = 0;
    vector<int> res;

    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0)
            sum += A[i];
    }

    n = queries.size();
    for (int i = 0; i < n; ++i) {
        int cur = A[queries[i][1]];
        int val = queries[i][0];

        if (cur % 2 == 0 && val % 2 == 0)
            sum += val;
        else if (cur % 2 != 0 && val % 2 != 0)
            sum += cur + val;
        else if (cur % 2 == 0 && val % 2 != 0)
            sum -= cur;
        A[queries[i][1]] += val;
        res.push_back(sum);
    }

    return res;
}