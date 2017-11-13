#include <set>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

enum coin {
    NONE = 0,
    NICKEL = 5,
    DIME = 10,
    QUARTER = 25
};

set<string> uniques;

class counts : public unordered_map<coin, int> {
    public:
        string to_string() {
            string s = string("");
            for (int i = 0; i < this->at(NICKEL); i++) {
                s += "N";
            }
            for (int i = 0; i < this->at(DIME); i++) {
                s += "D";
            }
            for (int i = 0; i < this->at(QUARTER); i++) {
                s += "Q";
            }
            return s;
        }
};

void R(int sum, int target, counts& c) {
    if (sum == target) {
        uniques.insert(c.to_string());
        return;
    }

    if (sum+NICKEL <= target) {
        c[NICKEL]++;
        R(sum+NICKEL, target, c);
        c[NICKEL]--;
    }
    if (sum+DIME <= target) {
        c[DIME]++;
        R(sum+DIME, target, c);
        c[DIME]--;
    }
    if (sum+QUARTER <= target) {
        c[QUARTER]++;
        R(sum+QUARTER, target, c);
        c[QUARTER]--;
    }
}

int main() {
    counts c;
    c[NICKEL] = 0;
    c[DIME] = 0;
    c[QUARTER] = 0;

    R(0, 100, c);

    cout << uniques.size() << " unique counted combinations." << endl;

    return 0;
}
