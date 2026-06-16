class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        isl =0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == "1":
                    isl+=1
                    self.search(grid,r,c)
        return isl
    
    def search(self, grid, r, c):
        if grid[r][c] == "1":
            grid[r][c] = "-1"
        else:
            return
        if r >0:
            self.search(grid,r-1,c)
        if c >0: 
            self.search(grid,r,c-1)
        if r < len(grid)-1:
            self.search(grid,r+1,c)
        if c < len(grid[0])-1:
            self.search(grid,r,c+1)


        