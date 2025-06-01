// Basic Calculator
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int number = 0;
        int sign = 1; // 1 means positive, -1 means negative

        for (char ch : s) {
            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * number;
                sign = 1;
                number = 0;
            } else if (ch == '-') {
                result += sign * number;
                sign = -1;
                number = 0;
            } else if (ch == '(') {
                // Save current result and sign
                st.push(result);
                st.push(sign);
                // Reset for the new expression inside parentheses
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * number;
                number = 0;
                result *= st.top(); st.pop(); // previous sign
                result += st.top(); st.pop(); // previous result
            }
            // ignore spaces
        }

        result += sign * number;
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.calculate("1 + 1") << endl;                   // Output: 2
    cout << sol.calculate(" 2-1 + 2 ") << endl;              // Output: 3
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;    // Output: 23
    return 0;
}
