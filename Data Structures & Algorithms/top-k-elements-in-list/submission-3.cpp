class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        std::priority_queue<pair<int,int>> min_pq;
        for(int i = 0; i< nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it!=m.end(); it++){
            min_pq.push({it->second,it->first});
        }
        vector<int> f;
        for(int i = 0; i< k; i++){
            f.push_back(min_pq.top().second);
            min_pq.pop();
        }
        return f;
    }
};
