#include <iostream>
#include <string>

using namespace std;

void paren(string& s, int lused, int rused, int curr, int pairs) {
    if (lused == pairs && rused == pairs) {
        cout << s << endl;
        return;
    }

    if (lused < pairs) {
        s[curr] = '(';
        paren(s, lused+1, rused, curr+1, pairs);
    }
    if (rused < pairs && rused < lused) {
        s[curr] = ')';
        paren(s, lused, rused+1, curr+1, pairs);
    }
}

int main() {
    string p = string("      ");
    paren(p, 0, 0, 0, 3);
    return 0;
}
