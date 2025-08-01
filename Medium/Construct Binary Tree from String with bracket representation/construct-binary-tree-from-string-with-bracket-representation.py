from typing import Optional
from collections import deque
"""
definition of binary tree node.
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
"""
class Solution:
    def treeFromString(self, s: str) -> Optional['Node']:
        def helper(start, end):
            if start > end:
                return None, end + 1

            # Find the root value
            i = start
            while i <= end and (s[i].isdigit() or s[i] == '-'):
                i += 1

            root_val = s[start:i] if start < i else None
            root = Node(int(root_val) if root_val is not None else None)

            # Check if there is a left subtree
            if i <= end and s[i] == '(':
                root.left, i = helper(i + 1, end)

            # Check if there is a right subtree
            if i <= end and s[i] == '(':
                root.right, i = helper(i + 1, end)

            return root, i + 1  # Skip ')'

        def inorder_traversal(node):
            if not node:
                return []
            left_vals = inorder_traversal(node.left)
            right_vals = inorder_traversal(node.right)
            return left_vals + [node.data] + right_vals if node.data is not None else left_vals + right_vals

        root, _ = helper(0, len(s) - 1)
        result = inorder_traversal(root)
        return result


class Solution:
    def treeFromString(self, s : str) -> Optional['Node']:
        # construct the first value
        i = 0
        v = s[i]
        while i < len(s) - 1 and s[i + 1] != "(" and s[i + 1] != ")":
            i += 1
            v += s[i]
        i += 1
        root = Node(v) # int(v) can be used
        
        p = [root, ] # Parent stack O(number of nodes)
        left = False
        while i < len(s):
            if s[i] == "(":
                i += 1
                continue
            elif s[i] == ")":
                # When left child is null
                if s[i - 1] == "(":
                    left = True
                    i += 1
                    continue
                else:
                    p.pop() # Going back to parent
            else:
                # Construct the value
                v = s[i]
                while i < len(s) - 1 and s[i + 1] != "(" and s[i + 1] != ")":
                    i += 1
                    v += s[i]
                new = Node(v)
                # Parent is the previous node in stack
                parent = p[len(p) - 1]
                p.append(new)
                # if left is already present or is null 
                if parent.left or left:
                    left = False
                    parent.right = new
                else:
                    parent.left = new
            i += 1
                    
        return root 



#{ 
 # Driver Code Starts
class Node:
    def __init__(self,val):
        self.data=val
        self.right=None
        self.left=None

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

def inputTree():
    treeString=input().strip()
    root = buildTree(treeString)
    return root
def inorder(root):
    if (root == None):
       return
    inorder(root.left);
    print(root.data,end=" ")
    inorder(root.right)

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        s = (input())
        
        obj = Solution()
        res = obj.treeFromString(s)
        
        inorder(res)
        print()
        

# } Driver Code Ends