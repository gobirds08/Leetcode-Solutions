# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        root = ListNode(-1, None)
        tail = root
        carry = 0
        in_loop = True
        while in_loop:
            temp_sum = 0
            if(l1 == None and l2 == None):
                in_loop = False
                if carry == 0:
                    break
            elif(l1 == None):
                temp_sum = l2.val
                l2 = l2.next
            elif(l2 == None):
                temp_sum = l1.val
                l1 = l1.next
            else:
                temp_sum = l1.val + l2.val
                l1 = l1.next
                l2 = l2.next

            if temp_sum + carry > 9:
                    temp_sum = temp_sum + carry - 10
                    carry = 1 
            else:
                temp_sum += carry
                carry = 0

            node = ListNode(temp_sum, None)
            if(root.val == -1):
                root = node
            else:
                tail.next = node
            tail = node
            
        return root


if __name__ == '__main__':
    l1_1 = ListNode(4, None)
    l1_2 = ListNode(7, l1_1)
    l2_1 = ListNode(5, None)
    l2_2 = ListNode(8, l1_1)
    l2_3 = ListNode(1, l2_2)
    solution = Solution()
    result = solution.addTwoNumbers(l1_1, l2_3)
    print(result)




