// This doesn't work.

#include <stdio.h>
#include <stdlib.h>

typedef struct element_t {
	int value;
	struct element_t* left;
	struct element_t* right;
} element;

void print_array(int a[], int l, int h) {
    for (int i = l; i <= h; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void R(element *elem, int out[], int used, int size) {
    if (!elem) return;

	out[used] = elem->value;
	if (used==size-1) {
		print_array(out, 0, used-1);
		return;
	}

    int n = 2;
    while (n-- > 0) {
        if (n == 2) {
            R(elem->left, out, used+1, size);
            R(elem->right, out, used+1, size);
        } else {
            R(elem->right, out, used+1, size);
            R(elem->left, out, used+1, size);
        }
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

	//element* one = newElem(1, NULL, NULL);
	//element* six = newElem(6, NULL, NULL);
	//element* nine = newElem(9, NULL, NULL);
	element* four = newElem(4, NULL, NULL);
	element* seven = newElem(7, NULL, NULL);
	element* five = newElem(5, four, seven);

    int out[3];

	R(five, out, 0, 3);
	return 0;
}
