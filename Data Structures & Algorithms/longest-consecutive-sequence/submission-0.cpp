class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> arr;
        unordered_set<int> u(nums.begin(), nums.end());
        
        // 0 --> 1
        // 3 --> 1
        // 1 --> 2
        // int max = max(max, u[...])
        int max  =0;
        for(int num : u){
            int length  = 0;
            if(u.find(num-1) == u.end()){
                while(u.find(num+length)!= u.end()){
                    length++;
                }
                max = std::max(max, length);
            }
        }
        return max;
    }
};
