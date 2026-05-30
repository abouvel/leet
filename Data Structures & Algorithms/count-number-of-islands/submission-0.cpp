class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>> coords;
        int x = 0; int y = 0;
        int islands = 0; 
        for(int y  = 0 ; y < grid.size(); y++){
            for(int x = 0; x <grid[0].size();x++){
                if(grid[y][x] == '1' && !visited[y][x]){
                    islands++;
                    coords.push({y,x});
                    while(!coords.empty()){
                        pair<int, int> p = coords.front();
                        coords.pop();
                        int yc = p.first;
                        int xc = p.second;
                        visited[yc][xc] = true;
                        addToQueue(yc,xc, coords, grid, visited);
                    }
                }
            }
        }
        return islands; 
    }

    void addToQueue(int y,int x, queue<pair<int,int>> & c,vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(y -1 >=0 && !visited[y-1][x]&& grid[y-1][x] == '1'){
            c.push({y-1,x});
        }
        if(y +1 <grid.size() && !visited[y+1][x]&& grid[y+1][x] == '1'){
            c.push({y+1,x});
        }
        if(x -1 >=0 && !visited[y][x-1]&& grid[y][x-1] == '1'){
            c.push({y,x-1});
        }if(x+1 < grid[0].size() && !visited[y][x+1]&& grid[y][x+1] == '1'){
            c.push({y,x+1});
        }
    }
};
