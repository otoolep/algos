#include <iostream>

using namespace std;

typedef struct element_t {
	int value;
	element_t* left;
	element_t* right;
} element;

bool bst_check(element *elem) {
    bool b;

    if (!elem) {
        return true;
    }

    b = bst_check(elem->left);
    if (!b) return b;

    b = bst_check(elem->right);
    if (!b) return b;

    if (elem->left && elem->right) {
        return (elem->left->value <= elem->value &&
                elem->right->value > elem->value);
    } else if (elem->left) {
        return elem->left->value <= elem->value;
    } else if (elem->right) {
        return elem->right->value > elem->value;
    }

    return true;
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

	if (bst_check(five)) {
        cout << "BST confirmed!" << endl;
    } else {
        cout << "Invalid BST!" << endl;
    }

    one->value = 10;
	if (bst_check(five)) {
        cout << "BST confirmed!" << endl;
    } else {
        cout << "Invalid BST!" << endl;
    }

	return 0;
}
