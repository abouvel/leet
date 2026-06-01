# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.m = 0
        self.recurs(root, 0)
        return self.m
    def recurs(self, root, cur):
        if not root:
            return
        cur +=1
        self.m = max(self.m, cur)
        self.recurs(root.left,cur)
        self.recurs(root.right,cur)