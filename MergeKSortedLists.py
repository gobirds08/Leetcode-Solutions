# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        head = None
        curr = head

        while True:
            allNone = True
            minNode = None
            minIndex = 0
            for i in range(len(lists)):
                if lists[i]:
                    if minNode == None or lists[i].val < minNode.val:
                        minNode = lists[i]
                        minIndex = i
                    allNone = False
            
            if allNone:
                break

            lists[minIndex] = lists[minIndex].next
            minNode.next = None

            

            if head == None:
                head = minNode
                curr = head
            else:
                curr.next = minNode
                curr = curr.next
        
        return head