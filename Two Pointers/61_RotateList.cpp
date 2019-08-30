//
// Created by neojxwang(王靖煊) on 2019-08-29.
//

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val_) : val(val_), next(NULL) {}
};

ListNode* rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;

    int n = 1;
    ListNode* tmp = head;
    while (tmp->next)
    {
        n++;
        tmp = tmp->next;
    }
    tmp->next = head;
    if (k > n)
        k %= n;

    n -= k;
    while (n--)
    {
        head = head->next;
        tmp = tmp->next;
    }

    tmp->next = NULL;
    return head;

}
