from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = defaultdict(list)
        for s in strs: 
            temp = "".join(sorted(s))
            m[temp].append(s)
        
        return list(m.values())