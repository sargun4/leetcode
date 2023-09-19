class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        N = len(nums) - 1
        seen = [0] * (N+1)
        for num in nums:
            if seen[num]:
                return num
            seen[num] = 1