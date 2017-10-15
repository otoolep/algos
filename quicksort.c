#include <stdio.h>

int partition(int a[], int l, int r) {
	int pivot = a[(l + r) / 2];

	while (l <= r) {
		/* find first left element that needs swapping. */
		while (a[l] < pivot) l++;

		/* find first right element that needs swapping. */
		while (a[r] > pivot) r--;

		if (l <= r) {
			int t = a[l];
			a[l] = a[r];
			a[r] = t;
			l++;
			r--;
		}
	}

	return l;
}

void quicksort(int a[], int l, int r) {
	if (l >= r) {
		return;
	}

	int i = partition(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i, r);
}

void print_array(int a[], int l, int r) {
	for (int i = 0; i <= r; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[] = {4,6,2,1,9,6,3,7,5,8};
	print_array(a, 0, 9);

	quicksort(a, 0, 9);
	print_array(a, 0, 9);

	return 0;
}