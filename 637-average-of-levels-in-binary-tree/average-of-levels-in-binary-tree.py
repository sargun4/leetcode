# class Solution:
#     def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
#         res = []
#         # initialize queue
#         q = collections.deque()
#         # add root node that we are given in queue
#         q.append(root)
#         # BFS
#         while q:
#             level = []
#             # going through one level at a time 
#             # with those nodes from that level
#             # we are going to add them to it's own list (level)
#             # and we are going to add that list to the result 
#             for i in range(len(q)):
#                 # pop nodes from the left of the queue
#                 node = q.popleft()
#                 # if node is not empty 
                
#                 if node:
#                     level.append(node.val)
                    
#                     q.append(node.left)
#                     q.append(node.right)
#             # if level is not empty
#             if level:
#                 # add level to the result '
#                 res.append(sum(level)/len(level))
#                 # print(len(level))
#         print(res)
#         return res 
# class Solution:
#     def printcurrlvl(self,root,lvl):
#         l=[]
#         if(root==None):
#             return []
#         if(lvl==1):
#             # print(root.data+" ")
#             l.append(root.data)
#         elif(lvl>1):
#             self.printcurrlvl(root.left,lvl-1)
#             self.printcurrlvl(root.right,lvl-1)
#         return l
    
#     def level(self,root):
#         if(root==None):
#             return 0
#         lht=self.level(root.left)
#         rht=self.level(root.right)
#         return Math.max(lht+rht)+1
    
#     def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
#         ht=self.level(root)
#         l=self.printcurrlvl(root,ht)
#         print(ht)
#         return l
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        q = deque([root])
        ans = []
        while q:
            qsize = len(q)
            sum_ = 0
            count = 0
            for _ in range(qsize):
                node = q.popleft()
                if node:
                    sum_ += node.val
                    count += 1
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(sum_/count)
        return ans
