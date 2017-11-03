#include <stdio.h>
#include <assert.h>

int COUNTS[256];

int count_bits_byte(unsigned char b) {
    int c = 0;
    unsigned char m = 0x1;
    for (int n = 0; n < 8; n++) {
        if (b & m) c++;
        m = m << 1;
    }
    return c;
}

int count_bits_int(unsigned int i) {
    int c = 0;
    for (int n = 0; n < 4; n++) {
        printf("%i %i\n", (unsigned char)i, COUNTS[(unsigned char)i]);
        c += COUNTS[(unsigned char)i];
        printf("1: 0x%x\n", i);
        i = i << 8;
        printf("2: 0x%x\n", i);
    }
    return c;
}


void create_lookup() {
    COUNTS[0] = 0;

    for (unsigned char i = 1; i > 0; i++) {
        COUNTS[i] = count_bits_byte(i);
    }
}

int main() {
    int a = 2;
    int max = a;
    int min = a;

    create_lookup();
    assert(COUNTS[1] == 1);
    assert(COUNTS[2] == 1);
    assert(COUNTS[3] == 2);

    //int ca = count_bits_int(a);
    int ca;
    //assert(ca = 1);

    //assert(count_bits_int(0xFF) == 8);
    assert(count_bits_int(0x00FF0000) == 8);
    assert(1==2);

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
