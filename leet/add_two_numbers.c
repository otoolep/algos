#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct Node_t {
 	int val;
 	struct Node_t *next;
 } Node;

 void printList(Node* n) {
 	while(n) {
 		printf("{%d} -> ", n->val);
 		n = n->next;
 	}
 	printf("{}\n");
 }

 Node* newNode(int val) {
 	Node* n = (Node*) malloc(sizeof(Node));
 	n->val = val;
 	n->next = NULL;
	return n;
 }

 Node* add_two_numbers(Node* left, Node* right) {
 	Node* sum = NULL;
 	int carry = 0;

 	while (left || right) {
 		int total = 0;

 		if (left) {
 			total = left->val;
 			left = left->next;
 		}
 		if (right) {
 			total = total + right->val;
 			right = right->next;
 		}

 		if (carry) {
 			total++;
 			carry = 0;
 		}

 		if (total > 9) {
 			total = total - 10;
 			carry = 1;
 		}

 		Node *n = newNode(total);
 		if (sum) {
 			n->next = sum;
 			sum = n;
 		} else {
 			sum = n;
 		}
 	}
 	return sum;
 }

int main() {
	Node *n1 = newNode(1);
	Node* n2 = newNode(2);
	n2 ->next = n1;

	printList(add_two_numbers(n1, n2));
	return 0;
}