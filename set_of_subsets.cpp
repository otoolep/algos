#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> set;

void print_vector(vector<string>out) {
    for (vector<string>::reverse_iterator s= out.rbegin(); s != out.rend(); ++s) {
        cout << *s << endl;
    }
}

void loop(vector<string>& out) {
    for (int i = 3; i >= 0; i--) {
        vector<string> clone(out);
        for (vector<string>::reverse_iterator s = out.rbegin(); s != out.rend(); ++s) {
            clone.push_back(*s + set[i]);
        }
        out = clone;
    }

    sort(out.begin(), out.end(), greater<string>());
    print_vector(out);
}

int main() {
    set.push_back("z");
    set.push_back("y");
    set.push_back("x");
    set.push_back("w");

    vector<string> out;
    out.push_back("");

    loop(out);

    return 0;
}
