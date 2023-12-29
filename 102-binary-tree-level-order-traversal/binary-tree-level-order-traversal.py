# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root):
        if root is None:
            return root
        q = []
        res = []
        q.append(root)
        while len(q) > 0:
            lvl = []
            l = len(q)
            for l in range(l):
                node = q.pop(0)
                lvl.append(node.val)
                if node.left != None:
                    q.append(node.left)
                if node.right != None:
                    q.append(node.right)
            res.append(lvl)
        return res

# from collections import deque
# class Solution:
    # def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    #       res = []
    #       queue = [[root]]
    #       while queue:
    #           level = queue.pop(0)
    #           # print([node.val for node in level if node])
    #           res.append([node.val for node in level])
    #           nlevel = []
    #           for node in level:
    #               print("NODE:", node.val)
    #               if node.left:
    #                   nlevel.append(node.left)
    #                   print("LEFT:", node.left.val)
    #               if node.right:
    #                   nlevel.append(node.right)
    #                   print("RIGHT:",node.right.val)
    #           print()
    #           if nlevel:
    #               queue.append(nlevel)
        
    #       return res