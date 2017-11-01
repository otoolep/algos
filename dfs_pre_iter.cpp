#include <iostream>
#include <stack>

using namespace std;

typedef struct element_t {
	int value;
	element_t* left;
	element_t* right;
} element;

void dfs_pre(element *elem) {
	stack<element*> s;
	s.push(elem);

	while (!s.empty()) {
		element* e = s.top();
		s.pop();
		if (!e) {
			continue;
		}
		cout << e->value << " ";

		s.push(e->right);
		s.push(e->left);
	}
	cout << endl;
}

element* newElem(int value, element* left, element* right) {
	element* e = (element*) malloc(sizeof(element));
	e->value = value;
	e->left = left;
	e->right = right;
	return e;
}

int main() {
	// Create a tree.
	//
	//           5
    //         4   7
    //       1  6   9

	element* one = newElem(1, NULL, NULL);
	element* six = newElem(6, NULL, NULL);
	element* nine = newElem(9, NULL, NULL);
	element* four = newElem(4, one, six);
	element* seven = newElem(7, NULL, nine);
	element* five = newElem(5, four, seven);

	dfs_pre(five);
	return 0;
}
