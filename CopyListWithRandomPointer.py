class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        nodes = {}
        if not head:
            return None

        current = head
        new_head = Node(head.val)
        new_current = new_head
        nodes[current] = new_current

        while current.next:
            current = current.next
            new_node = Node(current.val)
            new_current.next = new_node
            new_current = new_current.next
            nodes[current] = new_node

        new_current = new_head
        current = head
        print(len(nodes))

        while new_current:
            random = current.random
            points_to = None
            if random:
                points_to = nodes[random]
            new_current.random = points_to
            new_current = new_current.next
            current = current.next

        return new_head

