
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            size_t iterations = right - left;
            
            size_t i = 0;

            ListNode* leftNodePrev;
            ListNode* rightNodePrev;
            ListNode* curr = head;

            bool first = false;

            if (left == 1) {
                first = true;
            }

            while (i < right - 1) {
                i++;

                if (i == left - 1) {
                    leftNodePrev = curr;
                }

                if (i == right - 1) {
                    rightNodePrev = curr;
                }

                curr = curr->next;
            }

            i = 0;
            curr = head;

            while (i < iterations) {
                if (first) {
                    ListNode* rightTemp = rightNodePrev->next;
                    ListNode* leftTemp = head->next;
                    
                    head->next = rightTemp->next;
                    rightTemp->next = head;
                    head = leftTemp;
                } else {
                    ListNode* leftTemp = leftNodePrev->next;
                    ListNode* rightTemp = rightNodePrev->next;

                    leftNodePrev->next = leftTemp->next;
                    leftTemp->next = rightTemp->next;
                    rightTemp->next = leftTemp;
                }

                i++;
            }

            return head;
        }
};