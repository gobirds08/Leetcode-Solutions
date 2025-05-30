
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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* prev = head;
            if (head == nullptr) {
                return head;
            }
            ListNode* curr = head->next;

            while (curr != nullptr) {
                if (curr->val == prev->val) {
                    deleteNode(prev);
                } else {
                    prev = curr;
                }
                curr = curr->next;
            }

            return head;
        }

    private:
        void deleteNode(ListNode* prev) {
            // No bounds checking here
            prev->next = prev->next->next;
        }
};