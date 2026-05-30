class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.size(),vector<int>(text2.size(),-1));
        return recurs(v, 0,0,text1, text2);
    }
    int  recurs(vector<vector<int>> &v, int r, int c, string text1, string text2){
        if(r <0 || r >=v.size() || c < 0 || c >=v[0].size()){
            return 0;
        }
        if(v[r][c] != -1){
            return v[r][c];
        }

        v[r][c] = (text1[r] == text2[c]) ? 1 + recurs(v, r+1,c+1, text1, text2) : max(recurs(v, r+1,c, text1, text2),recurs(v, r,c+1, text1, text2));
        return v[r][c];

    }
};
