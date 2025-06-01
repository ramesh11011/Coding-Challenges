#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);  // Step 1: Push x into q2
        while (!q1.empty()) {
            q2.push(q1.front());  // Step 2: Push all elements of q1 to q2
            q1.pop();
        }
        swap(q1, q2);  // Step 3: Swap q1 and q2
    }

    int pop() {
        if (!q1.empty()) {
            int top = q1.front();
            q1.pop();
            return top;
        }
        return -1; // Error case
    }

    int top() {
        if (!q1.empty())
            return q1.front();
        return -1; // Error case
    }

    bool empty() {
        return q1.empty();
    }
};
