class Solution:
    def removeElement(self, nums, val):
        i = 0
        for x in nums:
            if x != val:
                nums[i] = x
                i += 1
        return i

# class Solution:
#     def removeElement(self, nums: List[int], val: int) -> int:
#         index = 0
#         for i in range(len(nums)):
#             if nums[i] != val:
#                 nums[index] = nums[i]
#                 index += 1
#         return index