# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        self.pvec = []
        self.qvec = []

        self.buildtree(p, True)
        self.buildtree(q, False)
        if len(self.pvec) != len(self.qvec):
            return False
        if self.pvec != self.qvec:
            return False
        return True
    def buildtree(self,treeNode, p):
        val = -101
        if treeNode:
            val = treeNode.val
        if p:
            self.pvec.append(val)
        else:
            self.qvec.append(val)
        if not treeNode:
            return
        self.buildtree(treeNode.left, p)
        self.buildtree(treeNode.right,p)


        