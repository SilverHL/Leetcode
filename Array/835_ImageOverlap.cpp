//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-17.
//

#include <vector>
#include <map>

int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
{
    map<pair<int, int>, int> move;
    vector<pair<int, int>> A1s, B1s;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (A[i][j])
                A1s.push_back({i, j});
        }
    }
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B[0].size(); ++j) {
            if (B[i][j])
                B1s.push_back({i, j});
        }
    }
    int res = 0;
    for (auto a : A1s) {
        for (auto b : B1s) {
            pair<int, int> dir = make_pair(b.first - a.first, b.second - a.second);
            move[dir]++;
            res = max(res, move[dir]);
        }
    }
    return res;
}

class Solution
{
    int popcount(unsigned int value) {
#if 1
        return __builtin_popcountll(value);
#else
        value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
        value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
        value = (value + (value >> 4)) & 0x0f0f0f0f;
        value = (value + (value >> 8));
        return (value + (value >> 16)) & 0xff;
#endif
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<unsigned int> a, b;
        for (auto& row : A) {
            int val = 0;
            for (int bit : row)
                val = (val << 1) + bit;
            a.push_back(val);
        }
        for (auto& row : B) {
            int val = 0;
            for (int bit : row)
                val = (val << 1) + bit;
            b.push_back(val);
        }
        int maxOverlap = 0, overlap;
        for (int si = 0; si < n; si++)
            for (int sj = 0; sj < n; sj++) {
                overlap = 0;
                for (int i = sj; i < n; i++)
                    overlap += popcount((a[i - sj] << si) & b[i]);
                maxOverlap = std::max(maxOverlap, overlap);
                overlap = 0;
                for (int i = sj; i < n; i++)
                    overlap += popcount((a[i] << si) & b[i - sj]);
                maxOverlap = std::max(maxOverlap, overlap);
                overlap = 0;
                for (int i = sj; i < n; i++)
                    overlap += popcount(a[i - sj] & (b[i] << si));
                maxOverlap = std::max(maxOverlap, overlap);
                overlap = 0;
                for (int i = sj; i < n; i++)
                    overlap += popcount(a[i] & (b[i - sj] << si));
                maxOverlap = std::max(maxOverlap, overlap);
            }
        return maxOverlap;
    }
};

int popcount(unsigned int value)
{
    return __builtin_popcount(value);
}

int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    vector<int> a, b;

    for (auto &row : A) {
        int tmp = 0;
        for (auto &bit : row) {
            tmp = (tmp << 1) + bit;
        }
        a.push_back(tmp);
    }

    for (auto &row : B) {
        int tmp = 0;
        for (auto &bit : row) {
            tmp = (tmp << 1) + bit;
        }
        b.push_back(tmp);
    }

    int overlap = 0, max_overlap = 0;
    for (int si = 0; si < n; si++) {
        for (int sj = 0; sj < n; sj++) {
            for (int i = sj; i < n; i++)
                overlap += popcount((a[i - sj] << si) & b[i]);
            max_overlap = max(overlap, max_overlap);

            overlap = 0;
            for (int i = sj; i < n; ++i)
                overlap += popcount(a[i - sj] & (b[i] << si));
            max_overlap = max(overlap, max_overlap);

            overlap = 0;
            for (int i = sj; i < n; i++)
                overlap += popcount((a[i] << si) & b[i - sj]);
            max_overlap = max(overlap, max_overlap);

            overlap = 0;
            for (int i = sj; i < n; i++)
                overlap += popcount(a[i] & (b[i - sj] << si));
            max_overlap = max(overlap, max_overlap);
        }
    }

    return max_overlap;
}
