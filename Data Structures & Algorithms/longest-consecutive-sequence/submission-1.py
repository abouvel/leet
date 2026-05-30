class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()

        for n in nums:
            s.add(n)
        
        counter = 0
        m = 0
        for i in range(len(nums)):
            if i != 0 and nums[i]-1 in s:
                continue
            elif nums[i] in s:
                n = nums[i]
                while n in s:
                    n +=1
                    counter +=1
                m = max(m, counter)
            counter = 0
        return m

        