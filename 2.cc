#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		int extra = 0;
		while (l1 != nullptr && l2 != nullptr) {
			int v = l1->val + l2->val + extra;
			extra = 0;
			if (v >= 10) {
				extra = 1;
				v %= 10;
			}
			ListNode *node = new ListNode(v);
			cur->next = node;
			cur = node;
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr) {
			int v = l1->val + extra;
			extra = 0;
			if (v >= 10) {
				extra = 1;
				v %= 10;
			}
			ListNode *node = new ListNode(v);
			cur->next = node;
			cur = node;
			l1 = l1->next;
		}

		while (l2 != nullptr) {
			int v = l2->val + extra;
			extra = 0;
			if (v >= 10) {
				extra = 1;
				v %= 10;
			}
			ListNode *node = new ListNode(v);
			cur->next = node;
			cur = node;
			l2 = l2->next;
		}
		if (extra > 0) {
			cur->next = new ListNode(extra);
		}

		return head->next;
	}
};