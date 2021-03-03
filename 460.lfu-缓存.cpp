#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start

struct Node 
{
    int key;
    int val;
    int freq;

    Node* next;
    Node* prev;

    Node(int k, int v, int f = 1) : key(k), val(v), freq(f), prev(nullptr), next(nullptr) {}
};

class DList
{
    Node *head;
    Node *tail;

public:
    DList() 
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }

    void insertHead(Node* node)
    {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void moveToHead(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        insertHead(node);
    }

    void removeNode(Node* node, bool re)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        if (re)
            delete node;
    }

    bool empty()
    {
        return head->next == tail;
    }

    ~DList()
    {
        Node *cur = head->next;
        Node *nxt = cur->next;

        if (!this->empty()) {
            while (cur != tail) {
                delete(cur);
                cur = nxt;
                nxt = nxt->next;
            }
        }

        delete head;
        delete tail;
    }

    Node removeTail()
    {
        Node tmp = *tail->prev;
        removeNode(tail->prev, false);
        return tmp;
    }
    
    Node getTail()
    {
        return Node(tail->prev->key, tail->prev->val, tail->prev->freq);
    }

    void list_val()
    {
        Node *cur = head->next;
        while (cur != tail)
        {
            cout << cur->key << " ";
            cur = cur->next;
        } 
        cout << endl;
    }
};


class LFUCache {
    unordered_map<int, Node*> keyToVal;
    unordered_map<int, DList*> freqToKey;
    int minFreq;
    int cap;

    static int cnt;

    void increseKey(int key)
    {
        Node* node = keyToVal[key];
        int freq = node->freq;
        DList* lst = freqToKey[freq];
        lst->removeNode(node, false);
        if (lst->empty() && node->freq == minFreq) {
            minFreq++; 
        } 
        freq += 1;
        insertMap(freq, node);
        keyToVal[key]->freq++;
    }

    void removeMinKey()
    {
        DList *lst = freqToKey[minFreq]; 
        Node tmp = lst->removeTail();
        keyToVal.erase(tmp.key);
        cout << "remove key " << tmp.key << endl;
    }

public:
    LFUCache(int capacity) {
        minFreq = 1;
        cap = capacity;
    }

    void insertMap(int freq, Node *node)
    {
        if (!freqToKey.count(freq)) {
            freqToKey[freq] = new DList();
        }
        freqToKey[freq]->insertHead(node);
    }

    int get(int key) {
  ;
        if (cap == 0) return -1;
        if (!keyToVal.count(key)) return -1;
        increseKey(key);
        return keyToVal[key]->val;
    }
    
    void put(int key, int value) {

        if (cap == 0) return;
        if (keyToVal.count(key)) {
            increseKey(key);
            keyToVal[key]->val = value;
        } else {
            if (keyToVal.size() >= cap) {
                removeMinKey();
            } 
            cout << "put key " << key << endl;
            Node *node = new Node(key, value);
            keyToVal.insert(pair<int, Node*>(key, node));
            minFreq = 1;
            insertMap(1, node);
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

