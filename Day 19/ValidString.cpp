#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty() || st.top() != matching[ch]) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("()[]{}") << endl;  // Output: 1 (true)
    cout << sol.isValid("([)]") << endl;    // Output: 0 (false)
    cout << sol.isValid("{[]}") << endl;    // Output: 1 (true)
    return 0;
}
