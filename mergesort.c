#include <stdio.h>

void print_array(int a[], int l, int h) {
	for (int i = l; i <= h; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// merge takes the two arrays indicated by a(l, m) and a(m+1, h)
// and merges them so that the a(l,h) is sorted, ascending. It
// assumes that both arrays are in sorted order, ascending.
void merge(int a[], int l, int m, int h) {
	int sz = h - l + 1;
	int t[sz];

	int i = 0;
	int idxL = l;
	int idxH = m+1;

	for (i = 0; i<sz; i++) {
		if (idxL <= m && idxH <= h) {
			if (a[idxL] < a[idxH]) {
				t[i] = a[idxL++];
			} else {
				t[i] = a[idxH++];
			}
		} else if (idxL <= m) {
			t[i] = a[idxL++];
		} else {
			t[i] = a[idxH++];
		}
	}

	// Copy results back over a.
	for (i = 0; i<sz; i++) {
		a[l+i] = t[i];
	}
}

void mergesort(int a[], int l, int h) {
	if (l == h) {
		return;
	}

	int m = ((h-l) / 2) + l;
	mergesort(a, l, m);
	mergesort(a, m+1, h);
	merge(a, l, m, h);
}

int main() {
	int a[] = {7,3,4,1,5,2,9,6,8};
	print_array(a, 0, 8);

	mergesort(a, 0, 8);
	print_array(a, 0, 8);
	return 0;
}