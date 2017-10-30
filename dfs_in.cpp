#include <iostream>

using namespace std;

typedef struct element_t {
	int value;
	element_t* left;
	element_t* right;
} element;

void dfs_in(element *elem) {
    if (!elem) {
        return;
    }

    dfs_in(elem->left);
    cout << elem->value << " ";
    dfs_in(elem->right);
}

element* newElem(int value, element* left, element* right) {
	element* e = (element*) malloc(sizeof(element));
	e->value = value;
	e->left = left;
	e->right = right;
	return e;
}

int main() {
	// Create a BST.
	//
	//           5
    //         4   7
    //       1   6   9

	element* one = newElem(1, NULL, NULL);
	element* six = newElem(6, NULL, NULL);
	element* nine = newElem(9, NULL, NULL);
	element* four = newElem(4, one, NULL);
	element* seven = newElem(7, six, nine);
	element* five = newElem(5, four, seven);

	dfs_in(five);
    cout << endl;
	return 0;
}
