# def search(root, key):
#     # Base Cases: root is null or key is present at root
#     if root is None or root.key == key:
#         return root
 
#     # Key is greater than root's key
#     if root.key < key:
#         return search(root.right, key)
 
#     # Key is smaller than root's key
#     return search(root.left, key)

class Solution:
    def insert(self,root, Key):
        if root is None:
            return Node(Key) 
        if Key < root.data:
            root.left = self.insert(root.left, Key)
        elif Key > root.data:
            root.right = self.insert(root.right, Key) 
        return root


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

def inOrder(n):
    if n is None:
        return
    inOrder(n.left)
    print(n.data, end=' ')
    inOrder(n.right)

if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        k=int(input())
        ob = Solution()
        ob.insert(root,k)
        inOrder(root)
        print()
# } Driver Code Ends