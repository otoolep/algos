#include <iostream>
#include <queue>

using namespace std;

typedef struct element_t {
	int value;
	element_t* left;
	element_t* right;
} element;

void bfs(element *elem) {
	queue<element*> q;
	q.push(elem);

	while (!q.empty()) {
		element* e = q.front();
		q.pop();
		if (!e) {
			continue;
		}
		cout << e->value << " ";

		q.push(e->left);
		q.push(e->right);
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

	bfs(five);
	return 0;
}