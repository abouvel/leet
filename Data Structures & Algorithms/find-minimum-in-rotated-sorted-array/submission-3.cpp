class Solution {
public:
    int findMin(vector<int> &nums) {
        
        bool min = false;
        int left = 0; 
        int right = nums.size()-1;
        int mid = 0;
        while(left <=  right){
            mid = (left + right)/2;
            if(nums[mid] > nums[right]){
                left = mid +1;
            }
            else if((mid > 0 && nums[mid]> nums[mid-1]) ||nums[mid] > nums[left]){
                right = mid -1;
            }
            else{
                return nums[mid];
            }
        }
        return nums[mid];
    }
};
