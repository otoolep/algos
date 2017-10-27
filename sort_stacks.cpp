#include <iostream>
#include <stack>

using namespace std;

void print(stack <int> x) {
    while(!x.empty()) {
        cout << x.top() << " ";
        x.pop();
    }
    cout << endl;
}

int main() {
    stack <int> a = stack<int>();
    stack <int> b = stack<int>();

    a.push(1);
    a.push(5);
    a.push(3);
    a.push(7);
    a.push(2);
    a.push(4);

    print(a);

    while(!a.empty()) {
        int x = a.top();
        a.pop();
        while (!b.empty() && b.top() < x) {
            a.push(b.top());
            b.pop();
        }
        b.push(x);
    }

    print(b);
    return 0;
}
