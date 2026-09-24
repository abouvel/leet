class Solution:
    def hammingWeight(self, n: int) -> int:
        bits = bin(n)
        counter = 0
        for b in bits: 
            if b == '1':
                counter +=1
        return counter
        