# class Solution:
#     def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
#         if not root:
#             return 0
#         sum = 0
#         if root.val > L:
#             sum += self.rangeSumBST(root.left, L, R)
#         if root.val < R:
#             sum += self.rangeSumBST(root.right, L, R)
#         if L <= root.val <= R:
#             sum += root.val     
#         return sum
class Solution:
    def lvlorder(self, root):
        res = []
        q = collections.deque()
        q.append(root)
        while q:
            lvl = []
            for i in range(len(q)):
                node = q.popleft()
                lvl.append(node)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(lvl)
        return res

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root:
            return 0
        
        res = 0
        q = collections.deque()
        q.append(root)

        while q:
            node = q.popleft()
            if node.val >= low and node.val <= high:
                res += node.val
            if node.left and node.val > low:
                q.append(node.left)
            if node.right and node.val < high:
                q.append(node.right)
        
        return res


# class Solution:
#     def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
#         if root:
#             if root.val<low:
#                 return self.rangeSumBST(root.right,low,high)
#             elif root.val>high:
#                 return self.rangeSumBST(root.left,low,high)
#             return root.val + self.rangeSumBST(root.left,low,high) + self.rangeSumBST(root.right,low,high)
#         else:
#             return 0
# class Solution:
#     def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
#         if root == None: return 0
#         if root.val > R: return self.rangeSumBST(root.left,L,R)
#         if root.val < L: return self.rangeSumBST(root.right,L,R)
#         return root.val + self.rangeSumBST(root.left,L,R) + self.rangeSumBST(root.right,L,R)      
                   