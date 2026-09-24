class Solution:
    def reverseBits(self, n: int) -> int:
        r = 0 
        for _ in range(32):
            b = n & 1
            n >>= 1
            r = (r << 1) | b
        return r