class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        def solve(root, s):
            s += str(root.val)
            if not root.right and not root.left: #reached leaf node
                ans.append(s)
                return
            if root.right:
                solve(root.right, s+"->")
            if root.left:
                solve(root.left, s+"->")
        solve(root, "")
        return ans
        
# class Solution:
#     def binaryTreePaths(self, root: TreeNode) -> List[str]:
#         if not root:
#             return []
#         self.res = []
#         self.dfs(root, str(root.val))
#         return self.res
    
#     def dfs(self, root, path):
#         if not root.left and not root.right:
#             self.res.append(path)
#         if root.left:
#             self.dfs(root.left, path + "->" + str(root.left.val))
#         if root.right:
#             self.dfs(root.right, path + "->" + str(root.right.val))
# # class Solution:
# #     def binaryTreePaths(self, root: TreeNode) -> List[str]:        
# #         result = []
# #         def helper(node, cur):
# #             if not node:
# #                 # base case
# #                 return
# #             if not node.left and not node.right:
# #                 # stop condition
# #                 result.append( cur + [str(node.val)] )                
# #             else:
# #                 # general case
# #                 helper(node.left, cur + [str(node.val)] )
# #                 helper(node.right, cur + [str(node.val)] )            
# #         helper(node=root, cur=[])
# #         return [ *map('->'.join, result) ]
# # class Solution:
# #     def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
# #         paths = []
# #         def dfs(node, path):
# #             if not node: return
# #             path = path + [node.val]
# #             if not (node.left or node.right):
# #                 return paths.append(path)
# #             dfs(node.left, path)
# #             dfs(node.right, path)
# #         dfs(root, [])
# #         return ['->'.join(map(str, path)) for path in paths]
