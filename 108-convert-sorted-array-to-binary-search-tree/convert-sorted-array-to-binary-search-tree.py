class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def helper(l,r):
            if(l>r):
                return None
            m=(l+r)//2
            root=TreeNode(nums[m])
            root.left=helper(l,m-1)
            root.right=helper(m+1,r)
            return root
        return helper(0,len(nums)-1)
# # T= O(n log n),S=O(n)
# class Solution:
#     def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
#         total_nums = len(nums)
#         if not total_nums:
#             return None

#         mid_node = total_nums // 2
#         return TreeNode(
#             nums[mid_node], 
#             self.sortedArrayToBST(nums[:mid_node]), self.sortedArrayToBST(nums[mid_node + 1 :])
#         )
# class Solution:
#     def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
#         return self.makeBST(nums, 0, len(nums))
    
#     def makeBST(self, nums, start, end):
#         if start >= end: return None
#         return TreeNode(
#             val=nums[ (start + end)//2 ],
#             left=self.makeBST(nums, start, (start + end)//2),
#             right=self.makeBST(nums, 1+((start+end)//2), end)
#         )