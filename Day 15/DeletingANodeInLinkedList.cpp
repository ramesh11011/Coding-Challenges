// Deleting A Node in the linked List 
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the data from the next node into this one
        node->val = node->next->val;

        // Skip the next node
        ListNode* temp = node->next;
        node->next = node->next->next;

        // Optional: delete the now-unused node
        delete temp;
    }
};
