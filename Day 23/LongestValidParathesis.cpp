#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);  // base index for valid substring
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);  // reset base
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << sol.longestValidParentheses("(()") << endl;        // Output: 2
    cout << sol.longestValidParentheses(")()())") << endl;     // Output: 4
    cout << sol.longestValidParentheses("") << endl;           // Output: 0
    return 0;
}
