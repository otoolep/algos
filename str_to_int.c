#include <stdio.h>
#include <string.h>
#include <assert.h>

#define BASE 10

int StrToInt(char* in) {
	assert(in);

	int i = 0;
	int v = 0;
	int isNeg = 0;

	if (in[0] == '-') {
		isNeg = 1;
		i = 1;
	}

	for (; i < strlen(in); i++) {
		v = v * BASE;
		v = v + (in[i] - '0');
	}

	if (isNeg) {
		return -v;
	}
	return v;
}

int main() {
	printf("Integer is: %d\n", StrToInt("-542"));
	return 0;
}