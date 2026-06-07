from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left = 0
        right = 0
        ret = ""
        tmap = defaultdict(int)
        for i in t:
            tmap[i]+=1
        minDist = 1001
        curMap = defaultdict(int)
        while right < len(s):
            curMap[s[right]] +=1
            while self.checkMap(tmap, curMap) and left <= right:
                if right-left+1 < minDist:
                    minDist = right-left+1
                    ret = s[left:right+1]
                curMap[s[left]] -=1
                left +=1
            right +=1
        return ret



    
    def checkMap(self, tmap, curMap):
        for key in tmap:
            if curMap[key] < tmap[key]:
                return False
        return True 


        