#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode.cn id=502 lang=cpp
 * 3\n0\n[1,2,3]\n[0,1,2]
 *
 * [502] IPO
 */

// @lc code=start

struct Node 
{
    int cost;
    int profit;

    Node(int c, int p) : cost(c), profit(p) {}
};

struct minCompare
{
    bool operator()(const Node & a, const Node & b) {
        return a.cost > b.cost;
    }
};

struct maxCompare
{
    bool operator()(const Node & a, const Node & b) {
        return a.profit < b.profit;
    }
};


class Solution
{
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

        if (Profits.empty()) return W;

        vector<Node> nodes;
        priority_queue<Node, vector<Node>, minCompare> minCost;
        priority_queue<Node, vector<Node>, maxCompare> maxProfit;

        int n = Profits.size();

        for (int i = 0; i < n; ++i) {
            nodes.push_back(Node(Capital[i], Profits[i]));
        }

        for (auto i : nodes) {
            minCost.push(i);
        }

        for (int i = 0; i < k; ++i) {
            while (minCost.top().cost <= W && !minCost.empty()) {
                maxProfit.push(minCost.top());
                minCost.pop();
            }

            if (maxProfit.empty()) break;

            W += maxProfit.top().profit;
            maxProfit.pop();
        }

        return W;
   }

};

// @lc code=end

