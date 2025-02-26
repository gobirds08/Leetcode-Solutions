

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (true){
            if (list1 != nullptr && list2 != nullptr){
                if(list2->val < list1->val){
                    curr->next = list2;
                    list2 = list2->next;
                }else{
                    curr->next = list1;
                    list1 = list1->next;
                }
            } else if (list1 != nullptr){
                curr->next = list1;
                list1 = list1->next;
            } else if (list2 != nullptr) {
                curr->next = list2;
                list2 = list2->next;
            } else {
                break;
            }
            curr = curr->next;
        }

        return head->next;
    }
};

int main(){
    Solution solution;

    ListNode* list1_1 = new ListNode(1);
    ListNode* list1_2 = new ListNode(2);
    ListNode* list1_3 = new ListNode(4);
    list1_1->next = list1_2;
    list1_2->next = list1_3;

    ListNode* list2_1 = new ListNode(1);
    ListNode* list2_2 = new ListNode(3);
    ListNode* list2_3 = new ListNode(4);
    list2_1->next = list2_2;
    list2_2->next = list2_3;

    solution.mergeTwoLists(list1_1, list2_1);
}