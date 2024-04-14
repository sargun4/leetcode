# Definition for a binary tree root.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     def isLeaf(self, root):
#         if root is None:
#             return False
#         if root.left is None and root.right is None:
#             return True
#         return False
    
#     def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
#         # Initialize result
#         res = 0
#         # Update result if root is not None
#         if root is not None:
#             # If left of root is None, then add val of
#             # left child
#             if self.isLeaf(root.left):
#                 res += root.left.val
#             else:
#                 # Else recur for left child of root
#                 res += self.sumOfLeftLeaves(root.left)

#             # Recur for right child of root and update res
#             res += self.sumOfLeftLeaves(root.right)
#         return res
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        # does this node have a left child which is a leaf?
        if root.left and not root.left.left and not root.left.right:
			# gotcha
            return root.left.val + self.sumOfLeftLeaves(root.right)

        # no it does not have a left child or it's not a leaf
        else:
			# bummer
            return self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
        