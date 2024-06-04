class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nextgreater = {}
        st = []
        for num in nums2:
            while st and st[-1] < num:
                nextgreater[st.pop()] = num
            st.append(num)
        return [nextgreater.get(num, -1) for num in nums1]
