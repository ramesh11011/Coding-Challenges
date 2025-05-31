#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Class containing the mergeTwoLists function
class Solution {
public:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
};

// Helper to create a linked list from an array
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper to print the linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test Case 1
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    ListNode* result1 = sol.mergeTwoLists(list1, list2);
    cout << "Merged List 1: ";
    printList(result1);

    // Test Case 2
    ListNode* list3 = nullptr;
    ListNode* list4 = nullptr;
    ListNode* result2 = sol.mergeTwoLists(list3, list4);
    cout << "Merged List 2: ";
    printList(result2);

    // Test Case 3
    int arr5[] = {0};
    ListNode* list5 = nullptr;
    ListNode* list6 = createList(arr5, 1);
    ListNode* result3 = sol.mergeTwoLists(list5, list6);
    cout << "Merged List 3: ";
    printList(result3);

    return 0;
}
