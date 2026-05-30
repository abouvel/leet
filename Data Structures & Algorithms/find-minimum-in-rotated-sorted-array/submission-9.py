class Solution:
    def findMin(self, nums: List[int]) -> int:
        #binary search
        #when to check left and right side though
        #if midpoint > the end search right
    
        return self.bst(0, len(nums)-1, nums)
    def bst(self,left, right, nums):
        mid = left + int((right-left)/2)
        if left >= right:
            return nums[left]
        if mid != 0 and mid != len(nums)-1 and nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1]:
            return nums[mid]
        if right == left:
            return nums[mid]
        elif nums[mid] > nums[right]:
            return self.bst(mid+1, right, nums)
        return self.bst(left, mid-1, nums)

        
        