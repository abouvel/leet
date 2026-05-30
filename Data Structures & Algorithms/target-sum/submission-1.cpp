class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(int i : nums){
            sum +=i;
        }
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum*2+1, -1));
        return recurs(dp, nums.size()-1, sum,nums, sum-target);
    }
    int recurs(vector<vector<int>> &dp, int index, int total, vector<int> &nums, int sum){
        if(dp[index][total]!= -1){
            return dp[index][total];
        }
        if(index == 0){
            dp[index][total] = (total + nums[0] == sum|| total - nums[0]== sum) ?1:0;
            if(nums[0] ==0 &&dp[index][total]==1){
                dp[index][total] = 2;
            }
        }else{
            dp[index][total] = recurs(dp, index-1, total + nums[index], nums, sum) + recurs(dp, index-1, total - nums[index], nums,sum);
        }
        return dp[index][total];
    }
};
