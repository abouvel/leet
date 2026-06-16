from collections import deque
from collections import defaultdict

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return
        head = Node(node.val)
        self.m = defaultdict(Node)
        self.recurs(head,node)
        return head
    def recurs(self, head, node):
        
        for n in node.neighbors:
            if n.val not in self.m:
                #we are creating this node
                newN = Node(n.val)
                self.m[n.val] = newN
                self.recurs(newN,n)
            head.neighbors.append(self.m[n.val])




        