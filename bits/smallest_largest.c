#include <stdio.h>

int COUNTS[256];

int count_bits_byte(unsigned char b) {
    int c = 0;
    unsigned char m = 0x1;
    for (int n = 0; n < 8; n++) {
        if (b & m) c++;
        m << 1;
    }
    return c;
}

int count_bits_int(unsigned int i) {
    int c = 0;
    for (int n = 0; n < 4; n++) {
        c += COUNTS[(unsigned char)i];
        i << 8;
    }
    return c;
}


void create_lookup() {
    for (int i = 0; i < 256; i++) {
        COUNTS[i] = count_bits_byte((unsigned char)i);
    }
}

int main() {
    int a = 1755;
    int max = a;
    int min = a;

    create_lookup();

    int ca = count_bits_int(a);

    for (int i = 0; max == a || min == a; i++)  {
        if (max == a) {
            if (count_bits_int(a + i) == ca) {
                max == a + i;
                if (max < a) {
                    return -1;
                }
            }
        }

        if (min == a) {
            if (count_bits_int(a - i) == ca) {
                min == a - i;
                if (min > a) {
                    return -1;
                }
            }
        }

    }

    printf("Max is %d, min is %d\n", max, min);

    return 0;
}
