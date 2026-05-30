class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> s;               // still just one stack!
        vector<int> ans(n, 0);

        // push the last day’s index, not its temperature
        s.push(n - 1);

        for (int i = n - 2; i >= 0; --i) {
            // pop until we find a strictly warmer day
            while (!s.empty() && T[s.top()] <= T[i]) {
                s.pop();
            }
            if (!s.empty()) {
                // here’s your “c” in one shot:
                ans[i] = s.top() - i;
            }
            // push this day’s index for future lookups
            s.push(i);
        }
        return ans;
    }
};
