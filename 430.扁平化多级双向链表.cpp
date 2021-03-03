#include <iostream>
/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {

    Node* flattenChild(Node* head)
    {
        Node *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        } 
        return cur;
    }
public:
    Node* flatten(Node* head) {
        if (head == nullptr) 
            return head;
        if (head->child != nullptr) {
            if (head->next == nullptr) {
                head->next = head->child;
                head->child->prev = head;
            } else {
                Node *tail = flattenChild(head->child);
                tail->next = head->next; 
                tail->next->prev = tail;
                head->next = head->child; 
                head->child->prev = head;
            }
            head->child = nullptr;
        }
        flatten(head->next);
        return head;
    }
};
// @lc code=end

