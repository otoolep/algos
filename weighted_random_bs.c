#include <stdio.h>

/* Iterative binary search. */
int BinarySearchI(int* array, int lower, int upper, int target) {
	if (!array) {
		return -1;
	}

	int center;
	while(lower <= upper) {
		center = (upper - lower) / 2 + lower;

		if (array[center] == target) {
			return center;
		}

		if (array[center] < target) {
			lower = center + 1;
		} else {
			upper = lower;
		}
	}

    return lower;
}

int main() {
	printf("Binary searches.....\n");

	int values[4] = {1,2,3,4};
	printf("%d\n", BinarySearchI(values, 0, 3, 2));
	return 0;
}
