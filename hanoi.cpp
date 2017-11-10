// Solution to Towers of Hanoi.
//
// Disks are represented by simple integers. Larger values
// represent larger disks.

#include <stack>
#include <vector>

using namespace std;

class Tower {
    stack<int> s;

    public:
        Tower() { s = stack<int>(); };
        ~Tower() {};

        // Returns top disk, or -1 if none.
        int pop() {
            if (s.empty()) {
                    return -1;
            }
            int v = s.top();
            s.pop();
            return v;
            }

        // Push disk onto stack, and returns value of
        // disk. If adding disk would violate invariants,
        // returns -1.
        int push(int v) {
            if (v <= s.top()) {
                return -1;
            }
            s.push(v);
            return v;
        }

        // Whether this tower has the smallest disk on top.
        bool hasSmallest() {
            return (!s.empty() && s.top() == 1);
        }

        // Returns whether this tower's top disk is smaller
        // than the other tower's top disk.
        bool operator <(const Tower* t) {
            if (s.empty() && !t->s.empty()) {
                return true;
            } else if (!s.empty() && t->s.empty()) {
                return false;
            }
            return s.top() < t->s.top();
        }
};

class Towers {
    vector<Tower*> towers;

    public:
        Towers(Tower* t1, Tower* t2, Tower *t3) {
            towers[0] = t1;
            towers[1] = t2;
            towers[2] = t3;
        };
        ~Towers() {};

        // Returns tower with smallest disk
        Tower* hasSmallest() {
            for (auto& t: towers) {
                if (t->hasSmallest()) {
                    return t;
                }
            }
        }

        // Returns tower to the right, cycling if necessary.
        Tower* toRight(const Tower* t) {
            for (int i = 0; i < 3; i++) {
                if (t == towers[i]) {
                    if (++i == 3) i = 0;
                    return towers[i];
                }
            }
        }

        // Returns tower to the left, cycling if necessary.
        Tower* toLeft(const Tower* t) {
            for (int i = 0; i < 3; i++) {
                if (t == towers[i]) {
                    if (--i == -1) i = 2;
                    return towers[i];
                }
            }
        }

};

int main() {

    while (0) {
        // locate tower with smallest disk.
        // pop disk from that tower
        // move to disk to right
        // are there N disks on middle tower? If so break.
        //
        // find smallest disk on other two towers.
        // pop disk from that tower to other
        //
    }
    return 0;
}
