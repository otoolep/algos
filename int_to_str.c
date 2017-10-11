#include <stdio.h>

#define MAX_INT_DIGITS 10

void IntToString(int n, char out[]) {
	int base = 10;
	int wr_pos = 0;
	int rem = 0;
	int isNeg = 0;
	char c;
	char temp;
	int start = 0;
	int end = 0;

	// Handle negative numbers after conversion.
	if (n < 0) {
		isNeg = 1;
		n = n * -1;
	}

	while(1) {
		// Get next least significant digit.
		rem = n % base;

		// Convert single chat to digit.
		c = rem + '0';
		out[wr_pos] = c;
		wr_pos++;

		n = n / base;
		if (n == 0) {
			// No more digits.
			break;
		}
	}

	// Add negative sign if necessary.
	if (isNeg) {
		out[wr_pos] = '-';
		wr_pos++;
	}

	// Reverse array.
	end = wr_pos - 1;
	while (start <= end) {
		temp = out[start];
		out[start] = out[end];
		out[end] = temp;
		start++;
		end--;
	}

	// Terminate string correctly.
	out[wr_pos] = '\0';
}

int main() {
	char out[MAX_INT_DIGITS + 2];
	char out2[MAX_INT_DIGITS + 2];


	IntToString(123, out);
	printf("String is %s\n", out);

	IntToString(-7899, out2);
	printf("String is %s\n", out2);
	return 0;
}