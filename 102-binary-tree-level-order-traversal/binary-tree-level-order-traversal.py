# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res=[]
        q=collections.deque()
        q.append(root)
        while q:
            qlen=len(q)
            lvl=[]
            for i in range(qlen):
                node=q.popleft()
                if node:
                    lvl.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if lvl:
                res.append(lvl)
        return res
        

# from collections import deque
# class Solution:
#     def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
#         if not root:
#             return []
#         Q = deque([root])
#         levels = [[root.val]]
#         temp = deque()

#         while Q:
#             node = Q.popleft()
#             if node.left: temp.append(node.left)
#             if node.right: temp.append(node.right)
            
#             if not Q:
#                 if temp:
#                     levels.append([n.val for n in temp])
#                 Q = temp
#                 temp = deque()

#         return levels