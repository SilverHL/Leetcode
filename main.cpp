#include <iostream>
#include <vector>

#include "460.lfu-缓存.cpp"

using namespace std;

int main()
{
    LFUCache *lfu = new LFUCache(2);
    lfu->put(1, 1);
    lfu->put(2, 2);
    cout << lfu->get(1) << endl;
    lfu->put(3, 3);
    cout << lfu->get(2) << endl;
    cout << lfu->get(3) << endl;
    lfu->put(4, 4);
    cout << lfu->get(1) << endl;;
    cout << lfu->get(3) << endl;
    cout << lfu->get(4) << endl;

    delete lfu;
}



