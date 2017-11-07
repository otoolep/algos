#include <iostream>
#include <queue>
#include <vector>
#include <functional>

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

    Timeseries* series = new Timeseries();

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

