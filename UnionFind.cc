#include <vector>
#include <iostream>

using namespace std;

class UnionFind
{
    vector<int> parent;
    vector<int> size;

    UnionFind(vector<int> &arr)
    {
        parent = vector<int>(arr.size(), 1);
        size = vector<int>(arr.size(), 1);
        for (auto i : arr)
        {
            parent[i] = i;
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    int find(int x)
    {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unionTogether(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px];
        }
        parent[px] = py;
    }
}