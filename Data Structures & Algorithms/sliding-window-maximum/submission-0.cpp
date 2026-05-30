class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max;
        vector<int> v;
        priority_queue<pair<int,int>> p;
        for(int i = 0; i < nums.size(); i++){
            p.push({nums[i], i});
            if(i>= k-1){
                while(p.top().second <=i-k){
                    p.pop();
                }
                v.push_back(p.top().first);

            }
        }
        return v;
    }
};
