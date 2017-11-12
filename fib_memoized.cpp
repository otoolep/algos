#include <stdio.h>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

int fib(int n) {
    try {
        memo.at(n);
    } catch (out_of_range) {
        int v;
        if (n == 0 || n == 1) v = n;
        else v = fib(n-1) + fib(n-2);
        memo[n] = v;
    }
    return memo[n];
}

int main() {
    int n = 48;

    printf("%d: %d\n", n, fib(n));
    return 0;
}
