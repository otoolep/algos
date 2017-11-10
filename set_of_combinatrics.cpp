#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void print_vector(vector<string>out) {
    for (vector<string>::reverse_iterator s= out.rbegin(); s != out.rend(); ++s) {
        cout << *s << endl;
    }
}

vector<string> subsets(string w) {
    vector<string> v = vector<string>();

    // For every number between 0 and 2^(size of string)
    for (int i = 1; i < pow(2, w.size()); i++) {
        string subset;

        // For every bit set in the number, create string using those characters.
        for (int j = 0; j < 32; j++) {
            if (i & (0x1 << j)) {
                subset.push_back(w[j]);
            }
        }

        v.push_back(subset);
    }
    return v;
}

int main() {
    string word = string("wxyz");
    print_vector(subsets(word));
    return 0;
}
