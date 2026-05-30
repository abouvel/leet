class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() - 1) {
            int jumpAmt = nums[i];
            if (jumpAmt == 0) return false;

            int bestIndex = i;
            int maxReach = i + jumpAmt;

            // If we can already reach the end from here
            if (maxReach >= nums.size() - 1) return true;

            // Look for the best next jump within range
            for (int x = i + 1; x <= i + jumpAmt && x < nums.size(); ++x) {
                if (x + nums[x] > maxReach) {
                    bestIndex = x;
                    maxReach = x + nums[x];
                }
            }

            // If we couldn't find a better place to jump to, we're stuck
            if (bestIndex == i) return false;

            i = bestIndex;
        }

        return true;
    }
};
