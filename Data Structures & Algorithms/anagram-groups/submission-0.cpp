
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;   // key = sorted word

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());               // O(L log L)
            buckets[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [_, group] : buckets) {               // C++17 structured binding
            result.push_back(move(group));
        }
        return result;
    }
};
