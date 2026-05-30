from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        right = 0
        m = defaultdict(int)
        maxy = 0
        while right < len(s):
            while s[right] in m and m[s[right]] > 0 and left < right:
                m[s[left]] -=1
                left +=1
            maxy = max(maxy, right-left + 1)
            m[s[right]] +=1
            right +=1
        return maxy
