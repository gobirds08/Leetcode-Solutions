struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* curr = head;

            if (!curr) {
                return head;
            }

            while (curr->next != nullptr) {

                curr = curr->next;
            }

            ListNode* tail = curr;

            curr = head;
            int i = 0;

            while (head != tail) {

                head = head->next;
                curr->next = tail->next;
                tail->next = curr;

                i++;
                curr = head;
            }

            return head;
        }
};

int main() {
    Solution solution;
    ListNode five (5);
    ListNode four (4);
    ListNode three (3);
    ListNode two (2);
    ListNode one (1);

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;

    solution.reverseList(&one);
}