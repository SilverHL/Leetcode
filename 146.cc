#include <iostream>
#include <unordered_map>

using namespace std;

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
        cout << "Delete " << node->key << " " << node->val << endl;
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

    void traverse()
    {
        DNode* cur = head->next;
        while (cur != tail) {
            cout << cur->key << " " << cur->val << endl;
            cur = cur->next;
        }

        cout << endl;
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
        if (mp.count(key))
        {
            lst->moveToHead(mp[key]);
            return mp[key]->val;
        }
        else
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
            DNode* head = lst->getHead();
            lst->moveToHead(mp[key]);
            head->val = value;
        }

    /*
        for (auto m : mp)
        {
            cout << m.first << endl;
            cout << m.second->key << " " << m.second->val << endl;
        }

        cout << endl;
        */
       lst->traverse();
    }
};


int main()
{
    LRUCache* lru = new LRUCache(1);
    lru->put(2, 1);
    lru->get(2);
    lru->put(3, 1);
    lru->get(2);
}