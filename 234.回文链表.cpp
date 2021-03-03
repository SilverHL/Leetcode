#include <iostream>
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

    ListNode* reverseLst(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head, *nxt = head;

        while (cur != nullptr)
        {
            nxt = cur->next;         
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;

    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast && fast->next == NULL) {
            slow = slow->next;
        }

        ListNode *left = head;
        ListNode *right = reverseLst(slow);

        while (true) {
            if (right == NULL)
                return true;
            else if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return false;
    }
};
// @lc code=end

