#include <stdio.h>

#define NICKEL 5
#define DIME 10
#define QUARTER 25

void R(int val, int sum, int target, int* count) {
    if (sum + val > target) {
        return;
    } else if (sum + val == target) {
        (*count)++;
        return;
    }

    R(NICKEL, sum+NICKEL, target, count);
    R(DIME, sum+DIME, target, count);
    R(QUARTER, sum+NICKEL, target, count);
}

int main() {
    int count = 0;

    R(0, 0, 100, &count);
    printf("%i combinations where order counts.\n", count);\

    return 0;
}
