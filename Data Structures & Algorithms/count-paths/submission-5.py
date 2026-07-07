class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        num = 0
        memo = [ [-1] * (n+1) for _ in range(m+1)]

        def recurs(y,x):
            if memo[y][x] != -1:
                return memo[y][x]
            if y == m-1 or x == n-1:
                return 1
            memo[y][x] = recurs(y+1,x) + recurs(y,x+1)
            return memo[y][x]
        
        return recurs(0,0)
            
        