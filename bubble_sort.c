#include <stdio.h>

void bubble_sort(int a[], int l, int r) {
	int i;
	int unsorted = 1;

	while (unsorted) {
		/* assume array is sorted */
		unsorted = 0;

		for (i = 0; i< r; i++) {
			if (a[i] > a[i+1]) {
				/* still not sorted */
				unsorted = 1;

				int t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;

			}
		}
	}
}

void print_array(int a[], int l, int r) {
	for (int i = 0; i <= r; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[] = {4,6,2,1,6,3,7,5};
	print_array(a, 0, 7);

	bubble_sort(a, 0, 7);
	print_array(a, 0, 7);

	return 0;
}