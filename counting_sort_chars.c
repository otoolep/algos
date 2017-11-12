// Sort an ASCII string in linear time!
// This is actually quite cool.

#include <stdio.h>
#include <string.h>

int main() {
    char* s = "azwxqewxsjlpouighjskhgdfsfb287364isadfgoqwtrSdgweuytrgf983thkjhlajfzdfnmfyt329874q";

    int counts[256];
    for (int i = 0; i < 256; i++) counts[i] = 0;

    for (int i = 0; i < strlen(s); i++) {
        counts[s[i]]++;
    }

    printf("%s\n", s);
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            for (int j = 0; j < counts[i]; j++) printf("%c", (unsigned char)i);
        }
    }
    printf("\n");

    return 0;
}


