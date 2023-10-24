# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res=[0]
        def dfs(root):
            if not root: 
                return -1
            l = dfs(root.left)
            r = dfs(root.right)
            res[0]=max(res[0],2+l+r)
            return max(l,r)+1
        dfs(root)
        return res[0]

            


# class Solution:
#     def diameterOfBinaryTree(self, root: TreeNode) -> int:
#         def height(root):
#             nonlocal diameter
#             if not root:
#                 return 0
            
#             left = height(root.left)
#             right = height(root.right)
#             diameter = max(diameter, left + right)
#             return max(left, right) + 1
        
#         diameter = 0
#         height(root)
#         return diameter

# class Solution:
#     def ht(self, root):
#         if root == None:
#             return 0
#         lht = self.ht(root.left)
#         rht = self.ht(root.right)
#         return max(lht, rht) + 1

#     def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
#         if root == None:
#             return 0
#         ldiam = self.diameterOfBinaryTree(root.left)
#         rdiam = self.diameterOfBinaryTree(root.right)

#         lht = self.ht(root.left)
#         rht = self.ht(root.right)
#         return max(lht + rht, max(ldiam, rdiam))

# class Solution:
#     def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
# 	    # Implement depth
# 	    def depth(node: Optional[TreeNode]) -> int:
# 		    return 1 + max(depth(node.left), depth(node.right)) if node else 0
# 		return depth(root.left) + depth(root.right)  # calculate diameter