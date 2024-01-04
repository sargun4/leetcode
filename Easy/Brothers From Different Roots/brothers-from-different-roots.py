#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    

# } Driver Code Ends

class Solution:
    def inorder(self, root, d):
        if not root:
            return 
        self.inorder(root.left, d)
        d[root.data] = d.get(root.data, 0) + 1
        self.inorder(root.right, d)
    def countPairs(self, root1, root2, x):  
        d1 = dict()
        d2 = dict()
        self.inorder(root1, d1)
        self.inorder(root2, d2)
        res = 0
        for i in d1:
            if (x - i) in d2:
                res += d2[x - i]
        return res
        
# class Solution:
#     def countPairs(self, root1, root2, x):
#         def search(root, data):
#             if root is None:
#                 return 0
#             if data == root.data:
#                 return 1
#             elif data < root.data:
#                 return search(root.left, data)
#             else:
#                 return search(root.right, data)

#         ctr = [0]  # Initialize ctr as a list to make it mutable
#         def solve(root1, root2, x):
#             nonlocal ctr  # Use nonlocal to modify the outer variable
#             if root1 is None:
#                 return
#             solve(root1.left, root2, x)
#             ctr[0] += search(root2, x - root1.data)
#             solve(root1.right, root2, x)
#         solve(root1, root2, x)
#         return ctr[0]

# class Solution:
#     def countPairs(self, root1, root2, x): 
#         #convert both bsts to arrs
#         q1=[root1]
#         l1=[]
#         while(q1):
#             node=q1.pop(0)
#             if(node):
#                 l1.append(node.data)
#             if(node.left):
#                 q1.append(node.left)
#             if(node.right):
#                 q1.append(node.right)
#         q2=[root2]
#         l2=[]
#         while(q2):
#             node=q2.pop(0)
#             if(node):
#                 l2.append(node.data)
#             if(node.left):
#                 q2.append(node.left)
#             if(node.right):
#                 q2.append(node.right)
#         # print(l1,l2)
#         l2map={}
#         for i in range(len(l2)):
#             elmnt=l2[i]
#             l2map[elmnt]=1
#         pairs=[]
#         for i in range(len(l1)):
#             elmnt=l1[i]
#             if (x - elmnt in l2map):
#                 pairs.append((x-elmnt,elmnt))
#         return len(pairs)

        


#{ 
 # Driver Code Starts.
if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s1=input()
        s2=input()
        root1=buildTree(s1)
        root2=buildTree(s2)
        x=int(input())
        ob = Solution()
        print(ob.countPairs(root1,root2,x))
# } Driver Code Ends