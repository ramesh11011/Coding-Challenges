#include <iostream>
using namespace std;

// Function to calculate the sum of squares of digits
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is happy using Floyd's Cycle Detection
bool isHappy(int n) {
    int slow = n;
    int fast = sumOfSquares(n);

    while (fast != 1 && slow != fast) {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
    }

    return fast == 1;
}

int main() {
    int n1 = 19;
    int n2 = 2;

    cout << "Is " << n1 << " a happy number? " << (isHappy(n1) ? "true" : "false") << endl;
    cout << "Is " << n2 << " a happy number? " << (isHappy(n2) ? "true" : "false") << endl;

    return 0;
}
