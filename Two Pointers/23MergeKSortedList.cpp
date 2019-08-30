#include <vector>
#include <iostream>
#include <queue>


using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*> &lists)
	{
		int k = (int)lists.size();
		if (k == 0)
			return NULL;
		if (k == 1)
			return lists[0];
		return doMerge(lists, 0, k - 1);
	}

	ListNode *doMerge(vector<ListNode*>& lists, int left, int right)
	{
		if (left == right)
			return lists[left];
		else if (left + 1 == right)
			return merge2Lists(lists[left], lists[right]);
		ListNode* l1 = doMerge(lists, left, (left + right) / 2);
		ListNode* l2 = doMerge(lists, (left + right) / 2 + 1, right);
		return merge2Lists(l1, l2);
	}

	ListNode* merge2Lists(ListNode *l1, ListNode *l2)
	{
		if (l1 == l2)
			return l1;
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		if (l1->val > l2->val)
			return merge2Lists(l2, l1);
		ListNode *newl2 = new ListNode(0); 
		newl2->next = l2;
		ListNode *p1 = l1;
		while (p1->next->val < newl2->next->val)
		{
			if (p1->next->val < newl2->next->val)
				p1 = p1->next;
			else
			{
				ListNode* temp = p1->next;
				p1->next = newl2->next;
				newl2->next = newl2->next->next;
				p1->next->next = temp;
				p1 = p1->next;
			}
		}

		if (!p1->next)
			p1->next = newl2->next;
		delete newl2;
		return l1;

	}
};


class Solution1
{
public:
	struct compare {
		bool operator()(const ListNode* l, const ListNode* r) {
			return l->val > r->val;
		}
	};

	ListNode *mergeKLists(vector<ListNode*> &lists)
	{
		priority_queue<ListNode *, vector<ListNode*>, compare> q;
		for (auto l : lists)
		{
			if (l)
				q.push(l);
		}
		if (q.empty())
			return NULL;
		ListNode *result = q.top();
		q.pop();

		if (result->next)
			q.push(result->next);
		ListNode *tail = result;
		while (!q.empty())
		{
			tail->next = q.top();
			q.pop();
			tail = tail->next;
			if (tail->next)
				q.push(tail->next);
		}

		return result;
	}
};