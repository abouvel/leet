class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1;
        int curMin = 1;
        int max1 = nums[0];
        for(int i =0; i< nums.size(); i++){
            //nums[i] = (nums[i]==0) ? 1: nums[i];
            int prevCmax = curMax;
            curMax = max(max(nums[i],curMax*nums[i]), curMin*nums[i]);
            curMin = min(min(prevCmax*nums[i], nums[i]), curMin*nums[i]);
            max1 = max(max1, curMax);
        }
        return max1;


   }
};
