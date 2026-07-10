from collections import defaultdict, deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        m = defaultdict(int)
        adjList = [[] for _ in range(numCourses)]
        for f,s in prerequisites: 
            adjList[f].append(s)
        
        for i in range(numCourses):
            for s in adjList[i]:
                m[s]+=1
        
        d = deque()
        for i in range(numCourses):
            if m[i] == 0:
                # start it 
                d.append(i)
        processed = 0
        while d:
            val = d.popleft()
            for a in adjList[val]:
                m[a]-=1
                if m[a] <= 0:
                    d.append(a)
            processed +=1
        return processed == numCourses


        


        