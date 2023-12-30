def pathCounts(root):
    ans = []

    def solve(root, s):
        s += str(root.data)
        if not root.left and not root.right:  # leaf
            ans.append(s)
            return
        if root.left:
            solve(root.left, s + "-")
        if root.right:
            solve(root.right, s + "-")

    solve(root, "")
    l = []
    n = len(ans)
    for i in range(len(ans)):
        x = ans[i]
        x = x.split("-")
        l.append(x)

    d = {}  # key=length ,val=no of paths corresp to that len
    for i in range(n):
        a = len(l[i])
        if a not in d:
            d[a] = 1
        else:
            d[a] += 1

    x = sorted(d)
    arr = []
    for i in x:
        arr.append([i, d[i]])

    for i in range(len(x)):
        print(arr[i][0], arr[i][1], end=" $")

        
#{ 
 # Driver Code Starts
from collections import deque


class Node:
    """ Class Node """
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None

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
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        s=input()
        root=buildTree(s)
        pathCounts(root)
        print()
#Contributed by: Harshit Sidhwa



# } Driver Code Ends