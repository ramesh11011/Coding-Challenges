#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;  // Stack for pushing new elements
    stack<int> output; // Stack for popping/peeking

    // Helper to move elements from input to output if output is empty
    void transferIfNeeded() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        transferIfNeeded();
        int val = output.top();
        output.pop();
        return val;
    }

    // Get the front element
    int peek() {
        transferIfNeeded();
        return output.top();
    }

    // Return whether the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << endl; // returns 1
    cout << "Pop: " << q.pop() << endl;   // returns 1
    cout << "Empty: " << q.empty() << endl; // returns false
    return 0;
}
