# class Solution:
#     def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
#         if not preorder or not inorder:
#             return None
#         rootval=preorder[0]
#         root=TreeNode(rootval)
#         root_inorder_idx=inorder.index(rootval)
#         root.left=self.buildTree(preorder[1:root_inorder_idx+1],inorder[:root_inorder_idx])
#         root.right=self.buildTree(preorder[root_inorder_idx+1:],inorder[root_inorder_idx+1:])
#         return root
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        root_val = preorder[0]
        root = TreeNode(root_val)
        # Find the index of the root value in the inorder traversal
        root_inorder_idx = inorder.index(root_val)
        # Split the inorder traversal into left and right subtrees
        inorder_left = inorder[:root_inorder_idx]
        inorder_right = inorder[root_inorder_idx + 1:]
        # Split the preorder traversal based on the sizes of the left and right subtrees
        preorder_left = preorder[1:1 + len(inorder_left)]
        preorder_right = preorder[1 + len(inorder_left):]
        # Recursively build the left and right subtrees
        root.left = self.buildTree(preorder_left, inorder_left)
        root.right = self.buildTree(preorder_right, inorder_right)
        return root
# class Solution:
#     def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
#         VAL_TO_INORDER_IDX = {inorder[i]: i for i in range(len(inorder))}
#         def buildTreePartition(preorder, inorder_start, inorder_end):
#             if not preorder or inorder_start < 0 or inorder_end > len(inorder):
#                 return None
#             root_val = preorder[0]
#             root_inorder_idx = VAL_TO_INORDER_IDX[root_val]
#             if root_inorder_idx > inorder_end or root_inorder_idx < inorder_start:
#                 return None
#             root = TreeNode(preorder.pop(0))
#             root.left = buildTreePartition(preorder, inorder_start, root_inorder_idx - 1)
#             root.right = buildTreePartition(preorder, root_inorder_idx + 1, inorder_end)
#             return root
#         return buildTreePartition(preorder, 0, len(inorder) - 1)



# class Solution(object):
#     def buildTree(self, preorder, inorder):
#         # Recursive solution
#         if inorder:   
#             # Find index of root node within in-order traversal
#             index = inorder.index(preorder.pop(0))
#             root = TreeNode(inorder[index])

#             # Recursively generate left subtree starting from 
#             # 0th index to root index within in-order traversal
#             root.left = self.buildTree(preorder, inorder[:index])
            
#             # Recursively generate right subtree starting from 
#             # next of root index till last index
#             root.right = self.buildTree(preorder, inorder[index+1:])
#             return root