#User function Template for python3

class Solution:
    def buildmap(self,node,parent_val,graph):# form undirected graph frm tree
        if not node:
            return
        if node.data not in graph:
            graph[node.data]=[]
            if(parent_val is not None):
                graph[parent_val].append(node.data)
                graph[node.data].append(parent_val)
            self.buildmap(node.left,node.data,graph)
            self.buildmap(node.right,node.data,graph)
    def minTime(self, root,target):
        graph={}
        self.buildmap(root,None,graph)
        # for node,neighbors in graph.items():
        #     print(node,neighbors)
        # print(graph)
        q=[(target)]
        vis=set([target])
        t=0
        while(q):
            size=len(q)
            for i in range(size):
                node=q.pop(0)
                for neighbor in graph[node]:
                    if neighbor in vis:
                        continue
                    vis.add(neighbor)
                    q.append(neighbor)
            t+=1
        return t-1
        

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

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        line=input()
        target=int(input())
        root=buildTree(line)
        print(Solution().minTime(root,target))

# } Driver Code Ends