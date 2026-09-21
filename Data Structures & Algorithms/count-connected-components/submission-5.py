from collections import deque

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        # turn into adjacency list
        # then i call bfs on the first one connecting all of the parts it sees until there is nothing left. i add each one to a set of seen one
        # i then increment the one i am searching for
            # if it is in the set continue
            # if not i call binary search again
            #increment a counter for a new set 
        # repeat this until i get to the end 
        
        self.adjList = [[] for _ in range(n)]

        self.seen = set()
        for b,e in edges: 
            self.adjList[b].append(e)
            self.adjList[e].append(b)

        def bfs(ind):

            d= deque()
            d.append(ind)
            self.seen.add(ind)
            while d:
                curSize = len(d)

                for i in range(curSize):
                    curInd = d.popleft()
                    for val in self.adjList[curInd]:
                        if val in self.seen:
                            continue
                        d.append(val)
                        self.seen.add(val)  


        numConnected = 0

        for i in range(n):
            if i in self.seen:
                continue
            numConnected +=1
            bfs(i)
        return numConnected

        