class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 0100 
        # 0111
        # 1011
        #
        # need to xor it. add a 0 to the left of them.
        
        MASK = 0xFFFFFFFF
        a &= MASK
        b &= MASK
        while b:
            a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK
        return a - (1 << 32) if a >= (1 << 31) else a

        