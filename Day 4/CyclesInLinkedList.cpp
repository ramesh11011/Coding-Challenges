#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle using Floyd's Cycle Detection Algorithm
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;             // Move slow by 1 step
        fast = fast->next->next;       // Move fast by 2 steps

        if (slow == fast) {
            return true;               // Cycle detected
        }
    }

    return false;                      // No cycle
}

// Function to create a linked list with an optional cycle
ListNode* createList(int arr[], int size, int pos) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    ListNode* cycleNode = nullptr;

    if (pos == 0) cycleNode = head;

    for (int i = 1; i < size; ++i) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;

        if (i == pos) {
            cycleNode = tail;
        }
    }

    if (pos != -1) {
        tail->next = cycleNode;  // Create cycle
    }

    return head;
}

int main() {
    // Example 1
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createList(arr1, 4, 1); // pos = 1
    cout << "Example 1 - Has Cycle: " << (hasCycle(head1) ? "true" : "false") << endl;

    // Example 2
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2, 0); // pos = 0
    cout << "Example 2 - Has Cycle: " << (hasCycle(head2) ? "true" : "false") << endl;

    // Example 3
    int arr3[] = {1};
    ListNode* head3 = createList(arr3, 1, -1); // pos = -1
    cout << "Example 3 - Has Cycle: " << (hasCycle(head3) ? "true" : "false") << endl;

    return 0;
}
