#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with middleNode method
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow by 1
            fast = fast->next->next;  // Move fast by 2
        }

        return slow; // slow is at the middle
    }
};

// Helper function to create a linked list from an array
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list from a given node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: Odd length
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original List 1: ";
    printList(head1);
    ListNode* mid1 = sol.middleNode(head1);
    cout << "Middle List 1:   ";
    printList(mid1);

    cout << endl;

    // Example 2: Even length
    int arr2[] = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createList(arr2, 6);
    cout << "Original List 2: ";
    printList(head2);
    ListNode* mid2 = sol.middleNode(head2);
    cout << "Middle List 2:   ";
    printList(mid2);

    return 0;
}
