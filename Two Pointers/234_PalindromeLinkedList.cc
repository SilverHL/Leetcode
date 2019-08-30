//
// Created by neojxwang(王靖煊) on 2019-08-18.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val_) : val(val_), next(NULL) {}
};

bool isPalindrome(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    /* find middle point */
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* reverse half the list */
    ListNode *cur = slow->next;
    ListNode *next = cur->next;
    ListNode *tmp = NULL;
    cur->next = NULL;

    /* break the list */
    slow->next = NULL;

    while (next != NULL) {
        tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }

    /* It doesn't matter the length of the list is odd or even,
     * because these two pointers will come to an end */
    while (head && cur) {
        if (head->val != cur->val)
            return false;
        head = head->next;
        cur = cur->next;
    }

    return true;
}
