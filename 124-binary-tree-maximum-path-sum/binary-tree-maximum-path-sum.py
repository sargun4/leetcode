class Solution:
    def __init__(self):
        self.maxSum = float('-inf')
    def maxPathSum(self, root: TreeNode) -> int:
        def traverse(root):
            if root:
                left = traverse(root.left)
                right = traverse(root.right)
                self.maxSum = max(self.maxSum,root.val, root.val + left, root.val + right, root.val + left + right)
                return max(root.val,root.val + left,root.val + right)
            else:
                return 0
        traverse(root)
        return self.maxSum
# class Solution:
#     def maxPathSum(self, root: TreeNode) -> int:
#         def maxPath(root):
#             nonlocal maxSum
#             if not root:
#                 return 0
            
#             left = maxPath(root.left)
#             right = maxPath(root.right)
#             maxSum = max(maxSum, left + right + root.val)
#             return max(left + root.val, right + root.val, 0)
        
#         maxSum = -math.inf  
#         maxPath(root)
#         return maxSum