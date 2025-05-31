#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        // Step 1: Find the range (1-digit, 2-digit, etc.)
        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Find the number that contains the digit
        long long num = start + (n - 1) / digitLength;

        // Step 3: Find the digit within the number
        string numStr = to_string(num);
        return numStr[(n - 1) % digitLength] - '0';
    }
};

int main() {
    Solution sol;
    
    int n1 = 3;
    int n2 = 11;

    cout << "The " << n1 << "rd digit is: " << sol.findNthDigit(n1) << endl;
    cout << "The " << n2 << "th digit is: " << sol.findNthDigit(n2) << endl;

    return 0;
}
