#include <stdio.h>

/* Recursive binary search. */
int BinarySearchR(int* array, int lower, int upper, int target) {
	if (!array) {
		return -1;
	}

	if (lower > upper) {
		return -1;
	}

	int center;
	center = (upper - lower) / 2 + lower;

	if (array[center] == target) {
		return center;
	} 

	if (array[center] < target) {
		return BinarySearchR(array, center+1, upper, target);
	}
	return BinarySearchR(array, lower, center-1, target);
}

/* Iterative binary search. */
int BinarySearchI(int* array, int lower, int upper, int target) {
	if (!array) {
		return -1;
	}

	int center;
	while(1) {
		if (lower > upper) {
			return -1;
		}

		center = (upper - lower) / 2 + lower;

		if (array[center] == target) {
			return center;
		}

		if (array[center] < target) {
			lower = center + 1;
		} else {
			upper = center - 1;
		}
	}
}

int main() {
	printf("Binary searches.....\n");

	int values[4] = {1,2,3,4};
	printf("%d\n", BinarySearchR(values, 0, 3, 2));
	printf("%d\n", BinarySearchI(values, 0, 3, 2));
	return 0;
}
