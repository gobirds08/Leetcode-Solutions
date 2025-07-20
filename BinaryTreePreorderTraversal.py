class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        output = []
        
        self.helper(root, output)

        return output

    def helper(self, node, output):
        if not node:
            return

        output.append(node.val)

        self.helper(node.left, output)
        self.helper(node.right, output)
