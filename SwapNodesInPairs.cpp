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
        ListNode* swapPairs(ListNode* head) {
            if (head == nullptr || head->next == nullptr){
                return head;
            }

            ListNode* temp = head;
            ListNode* curr_right = head->next;
            head = curr_right;
            temp->next = head->next;
            head->next = temp;
            curr_right = temp;

            while (curr_right->next != nullptr && curr_right->next->next != nullptr){
                temp = curr_right->next;
                curr_right->next = temp->next;
                temp->next = curr_right->next->next;
                curr_right->next->next = temp;
                curr_right = temp;
            }

            return head;
        }
};


int main(){
    Solution solution;

    ListNode* list1_1 = new ListNode(1);
    ListNode* list1_2 = new ListNode(2);
    ListNode* list1_3 = new ListNode(3);
    // ListNode* list1_4 = new ListNode(4);
    list1_1->next = list1_2;
    list1_2->next = list1_3;
    // list1_3->next = list1_4;


    solution.swapPairs(list1_1);
}