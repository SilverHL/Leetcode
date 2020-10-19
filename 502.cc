#include <vector>
#include <queue>

using namespace std;

struct Node 
{
    int cost;
    int profit;

    Node(int c, int p) : cost(c), profit(p){}
};

struct minCmp
{
    bool operator()(const Node& a, const Node& b) {
        return a.cost < b.cost;
    }
};

struct maxCmp
{
    bool operator()(const Node &a, const Node &b) {
        return a.profit > b.profit;
    }
};

class Solution
{
   int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<Node> profits;
        priority_queue<Node, vector<Node>, minCmp> minCost;
        priority_queue<Node, vector<Node>, maxCmp> maxProfit;
        int n = Profits.size();

        if (Profits.empty()) 
            return W;

        for (int i = 0; i < n; ++i) {                
            profits.push_back(Node(Capital[i], Profits[i]));
        }

        for (auto i : profits) {
            minCost.push(i);
        }

        for (int i = 0; i < k; ++i) {
            while (minCost.top().cost <= W && !minCost.empty()) {
                maxProfit.push(minCost.top());
                minCost.pop();
            }

            if (maxProfit.empty()) {
                break;
            }

            Node tmp = maxProfit.top();
            W += tmp.profit;
        }
        return W;
   }

};
