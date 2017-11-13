#include <stdio.h>

#define NICKEL 5
#define DIME 10
#define QUARTER 25

void R(int val, int sum, int target, int* count) {
    if (sum + val == target) {
        (*count)++;
        return;
    }

    if (sum+NICKEL <= target) {
        R(NICKEL, sum+NICKEL, target, count);
    }
    if (sum+DIME <= target) {
        R(DIME, sum+DIME, target, count);
    }
    if (sum+QUARTER <= target) {
        R(QUARTER, sum+QUARTER, target, count);
    }
}

int main() {
    int count = 0;

    R(0, 0, 100, &count);
    printf("%i combinations where order counts.\n", count);\

    return 0;
}
