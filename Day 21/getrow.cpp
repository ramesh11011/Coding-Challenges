#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};

int main() {
    Solution sol;
    int rowIndex = 3;
    vector<int> result = sol.getRow(rowIndex);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
