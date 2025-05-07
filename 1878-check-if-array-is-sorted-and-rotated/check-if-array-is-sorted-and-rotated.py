class Solution:
    def check(self, nums: List[int]) -> bool:
        n=len(nums)-1
        for i in range (n):
            if nums[i]>nums[i+1] : 
                nums = nums[i+1:] + nums[:i+1]

        
        for i in range (n):
            if nums[i]>nums[i+1] : 
                return False



        return True