#include <stdio.h>

void selection_sort(int a[], int l, int r) {
	if (l == r) {
		return;
	}

	for (int i = l; i <= r; i++) {
		if (a[i] < a[l]) {
			int t = a[i];

			a[i] = a[l];
			a[l] = t;
		}
	}

	return selection_sort(a, l+1, r);
}

void print_array(int a[], int l, int r) {
	for (int i = l; i <= r; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[] = {4,6,2,1,6,3};
	print_array(a, 0, 5);

	selection_sort(a, 0, 5);
	print_array(a, 0, 5);

	return 0;
}