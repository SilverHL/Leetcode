#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:

	ListNode* getPre(ListNode* head, int n)
	{
		ListNode *fst = head;
		while (head != NULL && n--)
		{
			head = head->next;
		}
		if (n == 0)
			return fst;
		if (n != -1)
			return NULL;
		return head;
	}

	ListNode* removeNthFromEnd(ListNode *head, int n)
	{
		ListNode* h = head;
		ListNode *p = getPre(head, n);
		if (p == h)
		{
			ListNode *pos = p->next;
			delete(h);
			return pos;
		}
		if (p == NULL)
			return NULL;
		ListNode *pre = head;
		while (p->next != NULL)
		{
			p = p->next;
			pre = pre->next;
		}

		ListNode *pos = p->next;
		pre->next = pre->next->next;
		delete(pos);
		return h;
	}
};


void test(int arr[], int size)
{
	int num = sizeof(arr) / sizeof(int);
	for (int i = 0; i < num && i < size; i++)
		std::cout << i;
}

int main19()
{
	Solution s;
	ListNode * h= new ListNode(1);
	ListNode *head = h;
	h->next = new ListNode(2);
	/*h = h->next;
	h->next = new ListNode(3);
	h = h->next;
	h->next = new ListNode(4);
	h = h->next;
	h->next = new ListNode(5);
	h = h->next;
	h->next = new ListNode(6);
	h = h->next;*/

//	s.removeNthFromEnd(head, 2);
	int arr[] = { 1, 2, 3, 4 };
	test(arr, sizeof(arr) / sizeof(int));
	getchar();
	return 0;
}