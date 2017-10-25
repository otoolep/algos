#include <stdio.h>

int main() {
    int a[] = {1, 2, 4, 3, 4, 2, 4, 4, 6, 4, 7, 4};

    int counter = 0;
    int current;

    for (int i = 0; i < 12; i++) {
        if (counter == 0) {
            current = a[i];
            counter++;
        } else if (current == a[i]) {
            counter++;
        } else {
            counter--;
        }
    }

    printf("The majority element is: %d\n", current);
    return 0;
}
