#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start

struct DNode
{
public:
    int key;
    int val;
    DNode *next;
    DNode *prev;
    DNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class DList
{
private:
    DNode *head;
    DNode *tail;

public:
    DList()
    {
        head = new DNode(0, 0);
        tail = new DNode(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void insertHead(DNode *node)
    {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void deleteNode(DNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void deleteTail()
    {
        deleteNode(tail->prev);
    }

    DNode* getTail()
    {
        return tail->prev;
    }
    DNode* getHead()
    {
        return head->next;
    }

    void moveToHead(DNode *node)
    {
        if (node == head->next) return;
        
        node->next->prev = node->prev;
        node->prev->next = node->next;

        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

};

class LRUCache
{
    DList *lst;
    unordered_map<int, DNode *> mp;
    int cap;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        lst = new DList();
    }

    int get(int key)
    {
        if (mp.count(key)) {
            lst->moveToHead(mp[key]);
            return mp[key]->val;
        } else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (mp.count(key) == 0) {
            if (mp.size() == cap) {
                DNode *tail = lst->getTail();
                mp.erase(tail->key);
                lst->deleteTail();
            }
            DNode *tmp = new DNode(key, value);
            lst->insertHead(tmp);
            mp.insert({key, tmp});
        } else {
            DNode* tmp = mp[key];
            lst->moveToHead(tmp);
            tmp->val = value;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
