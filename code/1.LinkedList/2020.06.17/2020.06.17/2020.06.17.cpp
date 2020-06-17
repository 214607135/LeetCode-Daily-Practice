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
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* res = head;
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenHead = even;

		while (even != NULL && even->next != NULL) {
			odd = getNextNext(odd);
			res->next = odd;
			res = res->next;
			even->next = odd->next;
			even = even->next;
		}
		res->next = evenHead;
		return head;
	}
	ListNode* getNextNext(ListNode* node) {
		if (node != NULL && node->next != NULL) {
			node = node->next->next;
			return node;
		}
		else {
			return NULL;
		}
	}
};