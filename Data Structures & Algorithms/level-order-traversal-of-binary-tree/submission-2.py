# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        d = deque()
        d.append((root, 0))
        
        v = []
        if not root:
            return v
        while d:
            curNode, level = d.popleft()
            if len(v) <= level:
                v.append([])
            v[level].append(curNode.val)
            if curNode.left:
                d.append((curNode.left,level+1))
            if curNode.right:
                d.append((curNode.right,level+1))
        return v





        
        