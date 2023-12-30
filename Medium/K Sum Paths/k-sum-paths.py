class Solution:
    def sumK(self, root, k):
        def dfs(node, current_sum, prefix_sums):
            if not node:
                return 0

            current_sum += node.data
            count_paths = prefix_sums.get(current_sum - k, 0)

            prefix_sums[current_sum] = prefix_sums.get(current_sum, 0) + 1

            count_paths += dfs(node.left, current_sum, prefix_sums)
            count_paths += dfs(node.right, current_sum, prefix_sums)

            # Backtrack to remove the current_sum from prefix_sums
            prefix_sums[current_sum] -= 1

            return count_paths

        prefix_sums = {0: 1}  # Start with an initial sum of 0
        return dfs(root, 0, prefix_sums)

# class Solution:
#     def sumK(self,root,k): 
#         ans=[]
#         def solve(root,s):
#             s+=str(root.data)
#             if not root.left and not root.right:#leaf node
#                 ans.append(s)
#                 return
#             if(root.left):
#                 solve(root.left,s+"-")
#             if(root.right):
#                 solve(root.right,s+"-")
#         solve(root,"")
#         print(ans)
#         a=[]
#         for i in range(len(ans)):
#             x=(ans[i])
#             x=x.split("-")
#             a.append(x)
#         # print(ans,a)
#         ans=a
#         print(ans)
#         n=len(ans)
#         for i in range(n):
#             l=ans[i]
#             for j in range(len(l)):
#                 l[j]=int(l[j])
#         print(ans)
        
#         #use subarrays/slidng window on each str in  mat

#         #finding k sum paths in the list of sums
#         #return a list of all such paths
#         res=set()
#         ctr=0
#         for i in range(len(ans)):
#             l=ans[i]
#             for j in range(i, len(ans)):
#                 subarr=l[i:j+1]
#                 currsum=sum(subarr)
#                 if currsum == k :
#                     ctr+=1
#         return ctr
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(100000)
from collections import deque
from collections import defaultdict
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
        d=int(input())
        ob = Solution()
        print(ob.sumK(root,d))
        
# } Driver Code Ends