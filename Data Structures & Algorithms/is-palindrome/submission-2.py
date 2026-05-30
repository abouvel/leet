class Solution:
    def isPalindrome(self, s: str) -> bool:
        a = ""
        for i in s:
            if i.isalnum():
                a +=i
        if not a:
            return True
        for i in range(int(len(a)/2)+1):
            if a[i].lower() != a[len(a)-1-i].lower():
                
                return False
        return True
        # Was it a car or a cat I saw?
        