from typing import List

class Solution:
    def maximumSetSize(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        s1, s2 = set(nums1), set(nums2) 
        # Remove common elements until the length becomes n//2
        while len(s1) > n // 2:
            common_elements = s1.intersection(s2)
            if not common_elements:
                break
            s1.remove(common_elements.pop())
        # Remove elements until the length becomes n//2
        while len(s1) > n // 2:
            s1.pop()
            
        while len(s2) > n // 2:
            common_elements = s1.intersection(s2)
            if not common_elements:
                break
            s2.remove(common_elements.pop()) 
        while len(s2) > n // 2:
            s2.pop() 
        # Return the size of the union of s1 and s2
        return len(s1.union(s2))
