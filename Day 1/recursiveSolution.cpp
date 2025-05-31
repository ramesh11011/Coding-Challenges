// Recursive solution for Reversal of the Linked List

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class recursiveSolution{
    public:
        ListNode* reverseLinkedList(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }

            ListNode* newhead = reverseLinkedList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = nullptr;
            return newhead;

    }

};

int main(){

}