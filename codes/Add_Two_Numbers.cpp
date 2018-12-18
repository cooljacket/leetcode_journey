#include "comm_header.h"

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
	// 这里的数字可能很大，所以不能先转成整数，应该是模拟加法
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * head = NULL;
		ListNode * tail = NULL;

		int add_on = 0;
		while (l1 != NULL || l2 != NULL) {
			AddValueToListNode(head, tail, add_on);
			if (l1 != NULL) {
				tail->val += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				tail->val += l2->val;
				l2 = l2->next;
			}

			// 两个个位数相加，加上进位数，最多19，进位数最大是1
			if (tail->val >= 10) {
				tail->val -= 10;
				add_on = 1;
			}
			else {
				add_on = 0;
			}
		}

		// 注意最终进位的情况
		if (add_on > 0)
			AddValueToListNode(head, tail, add_on);

		return head;
	}

private:
	void AddValueToListNode(ListNode* & head, ListNode* & tail, int val) {
		if (head == NULL) {
			head = tail = new ListNode(val);
		}
		else {
			tail->next = new ListNode(val);
			tail = tail->next;
		}
	}
};


int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		ListNode * l1 = input_ListNode();
		ListNode * l2 = input_ListNode();
		ListNode * result = input_ListNode();

		assert(equal(Solution().addTwoNumbers(l1, l2), result));
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
