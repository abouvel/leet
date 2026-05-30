class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> cur;
        recurs(0,  nums,  v, cur);
        return v;
    }
    void recurs(int index, vector<int>& nums, vector<vector<int>>& v, vector<int> cur){
        
        if(index == nums.size()){
            v.push_back(cur);
            return;
        }
        
        cur.push_back(nums[index]);
        recurs(index+1, nums, v, cur);
        cur.pop_back();
        recurs(index+1, nums, v, cur);
        
        
    }
};
