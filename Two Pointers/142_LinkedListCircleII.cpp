//
// Created by neojxwang(王靖煊) on 2019-08-25.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return NULL;

    ListNode *slow = head->next;
    ListNode *fast = head->next->next;

    while (slow != fast && slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (!slow || !fast || !fast->next)
        return NULL;

    ListNode *tmp = head;
    while (tmp != slow)
    {
        tmp = tmp->next;
        slow = slow->next;
    }

    return tmp;
}

