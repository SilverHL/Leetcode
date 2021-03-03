#include <iostream>
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    ListNode *target = nullptr;
    ListNode* reverseN(ListNode* head, int n) 
    {
        if (n == 1) {
            target = head->next;
            return head;
        } 

        if (head->next == nullptr) return head;
        ListNode *last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = target;
        return head; 
    }


};
// @lc code=end

