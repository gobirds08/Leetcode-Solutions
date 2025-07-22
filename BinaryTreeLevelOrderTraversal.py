class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        output = []

        def helper(nodes):
            curr_list = []
            all_null = True
            new_nodes = []

            for node in nodes:
                if node:
                    all_null = False
                    curr_list.append(node.val)
                    new_nodes.append(node.left)
                    new_nodes.append(node.right)


            
            if not all_null:
                output.append(curr_list)
                helper(new_nodes)

        helper([root])

        return output
