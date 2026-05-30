class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #search in rotated array
        #know how to search for a minimum. How to search for a select point?
        # we points/values to consider
        # consider the left and right endpoints. 
        # mid value and the target value
        # check left if value is in between left and right values same goes for right
        # if left is greater than middle and value is less than middle check left
        return self.bst(nums, 0, len(nums)-1, target)
    def bst(self, nums, left, right, target):

        mid = left + (right-left)//2
        if nums[mid] == target:
            return mid
        if left > right:
            return -1
        if nums[left] <= nums[mid]:
            if nums[left] <=target <= nums[mid]:
                right = mid -1
            else:
                left = mid +1
        else:
            if nums[mid] <= target <= nums[right]:
                left = mid +1
            else:
                right = mid -1
        return self.bst(nums, left, right, target)