'''
class Node:
   def _init_(self,val):
       self.data = val
       self.left = None
       self.right = None
'''
class Solution:        
   def maxPathSum(self, root): 
       def maxPath(root): 
           if not root:
               return 0
           if root.left == None and root.right== None:
               return root.data 
           left = maxPath(root.left)
           right = maxPath(root.right)
           # edge cases for negative val
           if root.left == None:
               return root.data + right
           if root.right == None:
               return root.data + left
           # store max of
           self.maxSum = max(self.maxSum, left+right+root.data)
           #    if leftTreePathSum < 0, rightPathSUm < 0, then it returns 0,
           # which is assumption as if current node is leaf, and start calculating the path starting from it 
           return max(left+root.data, right+root.data) 
       if not root:
           return 0
       if root.left == None and root.right== None:
           return root.data
 
       # maxSum = int_min
       self.maxSum = -float('inf')
       x = maxPath(root)
       if root.left == None or root.right == None:
           return max(self.maxSum, x)
       return self.maxSum  

#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque
import sys
sys.setrecursionlimit(10**6)  #Increasing the limit of recursion
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

if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        ob = Solution()
        print(ob.maxPathSum(root))
# } Driver Code Ends