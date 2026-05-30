class Solution {
public:
    int trap(vector<int>& height) {
        //maxL, maxR values, if Value le

        //create an array of L and R at each point. 
        vector<int> right(height.size(),0);
        vector<int> left(height.size(),0);
        left[0] = height[0];
        right[height.size()-1] = height[height.size()-1];
        for(int i = 1; i < height.size(); i++){
            left[i]= std::max(left[i-1], height[i]);
            right[right.size()-1-i] = std::max(right[right.size()-i], height[right.size()-1-i]);
        }
        int total = 0;
        for(int i = 0; i < height.size(); i++){
            total += std::min(left[i], right[i])-height[i];
        }
        return total;

    }
};
