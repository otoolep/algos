#include <stdio.h>
// A:          a1 → a2
//                    ↘
//                     c1 → c2 → c3 → c4
//                    ↗            
// B:     b1 → b2 → b3
//
// -- can't mark the nodes.
// -- can't travel backwards.
// -- O(1) memory rules out hashmaps, and storing info about each node.
// -- O(n) runtime implies 1 pass over all elements.
// -- can't just advance each because and look for same node, because of differing lengths.
// -- something about the topology, that the different lengths imply intersection? NOPE
// ANS: find length of each. Advance pointer on longer one by difference. Then do each one.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (!headA || !headB) {
		return null;
	}

	ListNode *a = headA;
	ListNode *b = headB;

	int lenA = 0;
	while (a) {
		lenA++;
		a = a -> next;
	}

	int lenB = 0;
	while (b) {
		lenB++;
		b = b->next;
	}

	if (lenA > lenB) {
		for (int i = 0; i < lenA = lenB; i++)
		headA = headA->next;		
	}

	if (lenB > lenA) {
		for (int i = 0; i < lenB = lenA; i++)
		headB = headB->next;		
	}

	while(1) {
		if (!headA || !headB) {
			return null;
		}

		if (headA == headB) {
			return headA;
		}
		headA = headA->next;
		headB = headB->next;
	}
}