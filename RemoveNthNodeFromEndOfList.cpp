#include <corecrt.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            size_t list_size = 0;
            ListNode* curr = head;
            while(curr != nullptr){
                list_size++;
                curr = curr->next;
            }

            size_t i = 0;
            curr = head;
            ListNode* prev = head;
            while (i != list_size - n){
                i++;
                prev = curr;
                curr = curr->next;
            }

            if (curr == head){
                return curr->next;
            }

            prev->next = curr->next;
            curr->next = nullptr;
            return head;
        }
};