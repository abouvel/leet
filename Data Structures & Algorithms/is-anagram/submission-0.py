class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        st = "".join(sorted(s))
        tt = "".join(sorted(t))
        if st!=tt:
            return False
        return True
        