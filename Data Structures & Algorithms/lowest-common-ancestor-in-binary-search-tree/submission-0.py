# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        
    # either looking for both. or found one and looking for other. 
    # bst so not completely random. we know how to partition. 
    # at every point we know the targets. if we have found one and if the other will be left or right
    # also know the current one 
        self.p = p
        self.q = q
        return self.recurs(root)

    def recurs(self, cur):
       # if we havent found any and targets are both less we search left and right, 
       #keep going until different sides

        if p.val <cur.val and q.val < cur.val:
            return self.recurs(cur.left)
        elif p.val >cur.val and q.val > cur.val:
            return self.recurs(cur.right)
        return cur
