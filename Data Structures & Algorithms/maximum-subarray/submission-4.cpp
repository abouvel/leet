class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int count = max;
        for(int i =1; i < nums.size(); i++){
            
            if(count < 0 && nums[i] > count){
                count = nums[i];
            }else {count += nums[i];}

            if(count > max){
                max = count;
            }
            if(count < 0 && count < max){
                count = 0;
            }
            
        }
        return max;

    }
};
