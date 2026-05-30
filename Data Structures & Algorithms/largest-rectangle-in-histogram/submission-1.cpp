class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> s; // pair: (start_index, height)
        int maxArea = 0;

        // Process each bar, and a sentinel 0 height at the end
        for (int i = 0; i <= n; ++i) {
            int h = (i == n ? 0 : heights[i]);
            int start = i;
            // Pop taller bars, computing area as we go
            while (!s.empty() && s.top().second > h) {
                auto [idx, ht] = s.top(); 
                s.pop();
                maxArea = max(maxArea, ht * (i - idx));
                start = idx;       // this popped bar's start becomes the start for h
            }
            s.push({start, h});
        }

        return maxArea;
    }
};
