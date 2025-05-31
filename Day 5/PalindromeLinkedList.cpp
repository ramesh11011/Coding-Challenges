#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle (slow will point to mid)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = prev; // Head of reversed second half
        while (second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

// Helper to create linked list from array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Example 1: [1, 2, 2, 1]
    int arr1[] = {1, 2, 2, 1};
    ListNode* head1 = createList(arr1, 4);
    cout << "Is Palindrome (Example 1): " << (sol.isPalindrome(head1) ? "true" : "false") << endl;

    // Example 2: [1, 2]
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    cout << "Is Palindrome (Example 2): " << (sol.isPalindrome(head2) ? "true" : "false") << endl;

    return 0;
}
