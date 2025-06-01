#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);  // Integer division truncates toward zero
            } else {
                st.push(stoi(token));  // Convert string to int
            }
        }

        return st.top();  // Final result
    }
};

int main() {
    Solution sol;
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << "Result 1: " << sol.evalRPN(tokens1) << endl;  // Output: 9
    cout << "Result 2: " << sol.evalRPN(tokens2) << endl;  // Output: 6
    cout << "Result 3: " << sol.evalRPN(tokens3) << endl;  // Output: 22

    return 0;
}
