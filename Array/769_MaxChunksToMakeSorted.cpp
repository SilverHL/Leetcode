//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-29.
//

int maxChunksToSorted(vector<int>& arr)
{
    int m = 0;
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        m = max(m, arr[i]);
        if (m == i)
            ans++;
    }

    return ans;
}
