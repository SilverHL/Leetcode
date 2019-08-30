//
// Created by neojxwang(王靖煊) on 2019-08-12.
//

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val_) : val(val_), next(NULL){}
};


ListNode* partition(ListNode* head, int x) {

    ListNode* dummyHead1 = new ListNode(-1);
    ListNode* dummyHead2 = new ListNode(-1);
    ListNode *subNode1 = dummyHead1, *subNode2 = dummyHead2;

    while (head) {

        if (head->val < x) {
            subNode1->next = head;
            subNode1 = subNode1->next;
        }
        else {
            subNode2->next = head;
            subNode2 = subNode2->next;
        }

        head = head->next;
    }

    subNode2->next = NULL;
    subNode1->next = dummyHead2->next;
    return dummyHead1->next;
}

ListNode* partition(ListNode* head, int x)
{
    ListNode *dummyhead1 = new ListNode(-1);
    ListNode *dummyhead2 = new ListNode(-2);

    ListNode *subNode1 = dummyhead1, *subNode2 = dummyhead2;

    while (head)
    {
        if (head->val < x)
        {
            subNode1->next = head;
            subNode1 = subNode1->next;
        } else {
            subNode2->next = head;
            subNode2 = subNode2->next;
        }
    }

    subNode2->next = nullptr;
    subNode1->next = dummyhead2;

    return dummyhead1->next;

}
