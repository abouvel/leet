class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dist(matrix.size(),vector<int>(matrix[0].size(),-1));

        int max = -1;
        for(int r = 0; r < matrix.size();r++){
            for(int c = 0; c < matrix[0].size(); c++){
                set<pair<int,int>> occupied;
                max = std::max(max, findDist(dist, matrix,occupied,c,r));
            }
        }
        return max;
    }

    int findDist(vector<vector<int>> &dist, vector<vector<int>> &matrix, set<pair<int,int>> &occupied, int x, int y){
        if(dist[y][x]!=-1){
            return dist[y][x];
        }
        dist[y][x]=1;
        if(y>0 && !occupied.count({x,y-1})&& matrix[y-1][x]> matrix[y][x]){
            occupied.insert({x,y-1});
            dist[y][x] = std::max(dist[y][x],1+ findDist(dist, matrix, occupied,x,y-1));
            occupied.erase({x,y-1});
        }
        if(y<matrix.size()-1 && !occupied.count({x,y+1})&& matrix[y+1][x]> matrix[y][x]){
            occupied.insert({x,y+1});
            dist[y][x] = std::max(dist[y][x],1+ findDist(dist, matrix, occupied,x,y+1));
            occupied.erase({x,y+1});
        }
        if(x>0 && !occupied.count({x-1,y})&& matrix[y][x-1]> matrix[y][x]){
            occupied.insert({x-1,y});
            dist[y][x] = std::max(dist[y][x],1+ findDist(dist, matrix, occupied,x-1,y));
            occupied.erase({x-1,y});
        }
        if(x<matrix[0].size()-1 && !occupied.count({x+1,y})&& matrix[y][x+1]> matrix[y][x]){
            occupied.insert({x+1,y});
            dist[y][x] = std::max(dist[y][x],1+ findDist(dist, matrix, occupied,x+1,y));
            occupied.erase({x+1,y});
        }
        return dist[y][x];
    }

    
};
