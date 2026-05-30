class Solution {
public:
    string minWindow(string s, string t) {
        
        bool b = false;
        int right = 0; 
        int left = 0;
        unordered_map<char, int> tMap;
        for(char ch : t){
            tMap[ch]++;
        }
        unordered_map<char, int> window;
        int have = 0; 
        int need = tMap.size();
        int minLen = INT_MAX;
        int lf = 0;
        for(int r = 0; r < s.size(); r++){
            window[s[r]]++;
            if(tMap.count(s[r]) && window[s[r]] == tMap[s[r]]){
                have++;
            }
            while(have == need){
                //need to move left as much as possible. 
                if((r-left+1) < minLen){
                    minLen = r-left+1;
                    lf = left;
                }
                window[s[left]]--;
                if(tMap.count(s[left]) && window[s[left]] < tMap[s[left]]){
                have--;
                }
                left++;
           }
        }
        return minLen == INT_MAX ? "" : s.substr(lf, minLen);

    } 
};
