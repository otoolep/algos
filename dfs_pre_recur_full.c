#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int l, int r) {
        for (int i = l; i <= r; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}

typedef struct element_t {
	int value;
	element_t* left;
	element_t* right;
} element;

void dfs_pre(element *elem, int level, int a[]) {
    a[level]=elem->value;
    if (elem->left) {
        dfs_pre(elem->left, level+1, a);
    }
    if (elem->right) {
        dfs_pre(elem->right, level+1, a);
    }
    if (!elem->left && !elem->right) {
        print_array(a, 0, level);
        return;
    }
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
    //               10
    element *ten = newElem(10, NULL, NULL);
	element* one = newElem(1, NULL, NULL);
	element* six = newElem(6, NULL, NULL);
	element* nine = newElem(9, NULL, ten);
	element* four = newElem(4, one, six);
	element* seven = newElem(7, NULL, nine);
	element* five = newElem(5, four, seven);

	int a[10];

	dfs_pre(five, 0, a);
	return 0;
}
