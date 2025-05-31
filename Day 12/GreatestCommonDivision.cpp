// Greatest common division

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// GCD helper function using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;

        while (current && current->next) {
            int g = gcd(current->val, current->next->val);
            ListNode* newNode = new ListNode(g);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        return head;
    }
};

// Utility function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1: Input = [18,6,10,3]
    vector<int> input = {18, 6, 10, 3};
    ListNode* head = createList(input);

    cout << "Original list: ";
    printList(head);

    ListNode* updated = sol.insertGreatestCommonDivisors(head);

    cout << "Updated list: ";
    printList(updated);

    return 0;
}
