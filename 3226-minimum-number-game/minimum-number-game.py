
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        n=len(nums)
        for idx in range(0,n,2):
            nums[idx],nums[idx+1]=nums[idx+1],nums[idx]
        return nums