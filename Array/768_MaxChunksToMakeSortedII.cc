//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/2.
//
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>

using namespace std;

int maxChunksToSorted(vector<int>& arr)
{
    const int n = arr.size();
    vector<int> arr1(arr);
    sort(begin(arr1), end(arr1));
    long int sum1 = 0;
    long int sum2 = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += arr[i];
        sum2 += arr1[i];
        if (sum1 == sum2)
            ans++;
    }
    return ans;
}

int maxChunksToSortedII(vector<int>& arr)
{
    const int n = arr.size();
    int ans = 1;
    vector<int> fwd = arr;
    vector<int> bwd = arr;

    for (int i = 1; i < n; ++i)
        fwd[i] = max(arr[i], fwd[i-1]);

    for (int i = n-2; i >= 0; --i)
        bwd[i] = min(arr[i], bwd[i+1]);

    for (int i = 0; i < n-1; ++i)
        if (fwd[i] <= bwd[i+1])
            ans++;

    return ans;
}

int maxChunksToSortedIISpaceOpt(vector<int>& arr)
{
    const int n = arr.size();
    int ans = 1;
    int mx = INT_MIN;
    vector<int> bwd = arr;

    for (int i = n-2; i >= 0; --i)
        bwd[i] = min(arr[i], bwd[i+1]);

    for (int i = 0; i < n-1; ++i) {
        mx = max(mx, arr[i]);
        if (mx <= bwd[i+1])
            ans++;
    }

    return ans;
}

// monotonous stack
int maxChunksToSortedIII(vector<int>& arr)
{
    const int n = arr.size();
    stack<int> stk;

    for (int i = 0; i < n; ++i) {
        if (stk.empty() || stk.top() <= arr[i]) {
            stk.push(arr[i]);
        } else {
            int curMax = stk.top(); stk.pop();
            while (!stk.empty() && stk.top() > arr[i]) {
                stk.pop();
            }
            stk.push(curMax);
        }
    }
    return stk.size();
}
