#include <iostream>
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode *reverseBetween(ListNode *head, ListNode *b)
    {
        ListNode *pre = nullptr, *cur = head, *nxt = nullptr;

        while (cur != b) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *beg = head, *end = head;
        for (int i = 0; i < k; ++i) {
            if (end == nullptr) return head;
            end = end->next;
        }
        ListNode *newHead = reverseBetween(beg, end);
        beg->next = reverseKGroup(end, k);
        return newHead;
    }
};
// @lc code=end

