#include <stdio.h>

// An insertion sort moves 1 each time, but is prepared to
// go "all the way back". In practise it doesn't have to.
void insertion_sort(int a[], int l, int r) {
        if (r-l == 1 || r-l == 0) {
            return;
        }

        for (int i = l+1; i <= r; i++) {
            for (int j = i; j > l; j--) {
                if (a[j] < a[j-1]) {
                    int t = a[j-1];
                    a[j-1] = a[j];
                    a[j] = t;
                } else {
                    break;
                }
            }

        }
}

void print_array(int a[], int l, int r) {
        for (int i = l; i <= r; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}

int main() {
        int a[] = {7,4,6,2,1,6,3};
        print_array(a, 0, 6);

        insertion_sort(a, 0, 6);
        print_array(a, 0, 6);

        return 0;
}
