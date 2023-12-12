class Solution(object):
    def maxProduct(self, nums):
        first, second = 0, 0
        for no in nums:
            if no > first:
                # update first largest and second largest
                first, second = no, first
            elif no > second:
                # update second largest
                second = no
        return (first - 1) * (second - 1)