#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Point {
    public:
        int timestamp;
        int value;

        Point() {};
        Point(int t, int v) {
            this->timestamp = t;
            this->value = v;
        };

        bool operator()(const Point& a, const Point& b) {
            // This means that in a standard ascending ordering,
            // a would come after b. This doesn't reflect the
            // real world, because in the real world we want a
            // to come before b. But a priority queue spits out
            // the elements in descending order. So the combination
            // of this compare, and the priority queue, means we
            // get elements output in increasing order.
            return a.timestamp > b.timestamp;
        };
};

typedef priority_queue<Point, vector<Point>, Point> Timeseries;

int main() {
    Point p1(1,7);
    Point p2(2,4);
    Point p3(3,6);
    Point p4(4,9);
    Point p5(5,1);
    Point p6(6,10);

    Timeseries* series = new Timeseries();

    series->push(p6);
    series->push(p2);
    series->push(p4);
    series->push(p5);
    series->push(p1);
    series->push(p3);

    while (!series->empty()) {
        Point p = series->top();
        series->pop();

        cout << p.timestamp << ": " << p.value << endl;
    }

    return 0;
}

