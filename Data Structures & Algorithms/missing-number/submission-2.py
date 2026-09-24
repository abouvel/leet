class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        m = max(nums)
        exp = 0
        for i in range(1,len(nums)+1):
            exp = exp ^ i

        for n in nums:
            exp = exp ^ n
        return exp

        