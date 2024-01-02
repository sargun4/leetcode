# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        n = len(inorder)
        instart, inend = 0, n - 1
        poststart, postend = 0, n - 1
        def solve(inorder, postorder, instart, inend, poststart, postend):
            if instart > inend:
                return None
            root = TreeNode(postorder[postend])
            # find the index of root in inorder
            idx = instart
            while idx <= inend:
                if inorder[idx] == root.val:
                    break
                idx += 1
            lsize=idx-instart
            rsize=inend-idx
            root.right=solve(inorder,postorder,idx+1,inend,postend-rsize,postend-1)
            root.left=solve(inorder,postorder,instart,idx-1,poststart,poststart+lsize-1)
            return root
        return solve(inorder, postorder, instart, inend, poststart, postend)


# class Solution:
#     def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
#         if not inorder or not postorder:
#             return None
#         # Get the root value from the last element of postorder list
#         root_val = postorder.pop()
#         root = TreeNode(root_val)
#         # Find the index of the root value in the inorder list
#         root_idx = inorder.index(root_val)
#         # Recursively build the right subtree first
#         root.right = self.buildTree(inorder[root_idx + 1:], postorder)
#         # Recursively build the left subtree
#         root.left = self.buildTree(inorder[:root_idx], postorder)
#         return root


# class Solution:
#     def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
#         if not inorder or not postorder:
#             return None
#         root=TreeNode(postorder[-1])
#         index=inorder.index(postorder[-1])
#         root.left=self.buildTree(inorder[:index],postorder[:index])
#         root.right=self.buildTree(inorder[index+1:],postorder[index:-1])
#         return root

# class Solution:
#     def buildTree(self, inorder, postorder):
#         map_inorder = {}
#         for i, val in enumerate(inorder): map_inorder[val] = i
#         def recur(low, high):
#             if low > high: return None
#             x = TreeNode(postorder.pop())
#             mid = map_inorder[x.val]
#             x.right = recur(mid+1, high)
#             x.left = recur(low, mid-1)
#             return x
#         return recur(0, len(inorder)-1)