#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge cases like removing the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first n+1 steps ahead so there's a gap of n between first and second
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first) {
            first = first->next;
            second = second->next;
        }

        // Delete the nth node from the end
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Utility function to create a linked list from vector
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

// Utility function to print a linked list
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
    vector<int> input = {1, 2, 3, 4, 5}; // Test Case 1
    int n = 2;

    ListNode* head = createList(input);

    cout << "Original list: ";
    printList(head);

    head = sol.removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
