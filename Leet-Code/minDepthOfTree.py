# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from queue import Queue

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0

        q = Queue(0)
        q.put((root, 1))

        while True:
            node, depth = q.get()

            if node.left is None and node.right is None:
                break

            if node.left is not None:
                q.put((node.left, depth + 1))
            if node.right is not None:
                q.put((node.right, depth + 1))
        
        return depth