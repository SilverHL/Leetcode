#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */



// @lc code=start

struct Node 
{
    vector<int> v;
    int len;    

    Node(vector<int> v) : v(v) {
        len = v[0] * v[0] + v[1] * v[1];
    }
};

struct cmp
{
    bool operator()(const Node &n1, const Node &n2) {
        return n1.len > n2.len;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Node, vector<Node>, cmp> que;
        vector<vector<int>> res;

        for (auto v : points) {
            que.push(Node(v));
        }

        while (K-- && !que.empty()) {
            res.push_back(que.top().v);
            que.pop();
        }

        return res; 
    }
};
// @lc code=end

