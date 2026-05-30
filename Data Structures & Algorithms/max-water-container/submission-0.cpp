class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; 
        int right = heights.size()-1;
        int max = 0;
        while(left <right){
            int cur = std::min(heights[right],heights[left])*(right-left);
            if(heights[right] < heights[left]){
                right--;
            }else{
                left++;
            }
            if(cur >max){
                max = cur;
            }
        } 
        return max;


    }
};
