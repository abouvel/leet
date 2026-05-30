class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>, int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0){
                    q.push({{r,c}, 0});
                    while(!q.empty()){
                        pair<pair<int, int>,int> p =q.front();
                        q.pop(); 
                        add(p.first.first, p.first.second, grid, q, p.second+1);
                    }
                }
            }
        }
        
    }
    void add(int r, int c, vector<vector<int>>& grid, queue<pair<pair<int,int>, int>> &q, int dist){
        if(r >0 && grid[r-1][c] > dist){
            grid[r-1][c] = dist;
            q.push({{r-1,c}, dist});
        }if(r <grid.size()-1 && grid[r+1][c] > dist){
            grid[r+1][c] =dist;
            q.push({{r+1,c},dist});
        }if(c >0 && grid[r][c-1] > dist){
            grid[r][c-1] = dist;
            q.push({{r,c-1},dist});
        }if(c < grid[0].size()-1 && grid[r][c+1] > dist){
            grid[r][c+1] = dist;
            q.push({{r,c+1},dist});
        }

    }
};
