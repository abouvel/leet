class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, -1));
        return recurs(v, 0,0);
    }
    int recurs(vector<vector<int>> &v, int r, int c){
        if(r >= v.size() || c >= v[0].size() || r < 0|| c < 0){
            return 0;
        }
        if(v[r][c]!= -1){
            return v[r][c];
        }
        v[r][c] = (r == v.size()-1 && c == v[0].size()-1) ? 1 : recurs(v, r+1 ,c ) + recurs(v,r, c+1);
        return v[r][c];

    }
};
