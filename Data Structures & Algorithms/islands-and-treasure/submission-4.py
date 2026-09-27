from collections import deque

class Solution:
    
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2 ** 31 - 1
        d = deque()
        def search():
            
            val = 0
            s =set()
            s.add(d[0])
            while d:
                size = len(d)
                for i in range(size):
                    r1, c1 = d.popleft()
                    
                        
                    grid[r1][c1] = min(grid[r1][c1],val)
                    if r1 < len(grid)-1 and grid[r1+1][c1] > 0 and (r1+1,c1) not in s:
                        d.append((r1+1,c1))
                        s.add((r1+1,c1))
                    if r1 > 0 and grid[r1-1][c1] > 0 and (r1-1,c1) not in s:
                        d.append((r1-1,c1))
                        s.add((r1-1,c1))
                    if c1 < len(grid[0])-1 and grid[r1][c1 +1] > 0 and (r1,c1+1) not in s:
                        d.append((r1,c1+1))
                        s.add((r1,c1+1))
                    if c1 > 0 and grid[r1][c1-1] >0  and (r1,c1-1) not in s:
                        d.append((r1,c1-1))
                        s.add((r1,c1-1))
                val +=1


                                   



        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 0:
                    d.append((r,c))
        if d:
            search()
