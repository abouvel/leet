class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix[0].size()-1;
        int y = 0;
        while(x>= 0 && y <= matrix.size()-1){
            if(matrix[y][x]> target)
                x= x-1;
            else if (matrix[y][x]< target)
                y = y+1;
            else{
                return true;
            }
        }
        return false;
    }
};
