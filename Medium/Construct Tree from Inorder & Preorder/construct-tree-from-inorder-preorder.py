class Solution:
    def buildtree(self, inorder, preorder,n):
        if not inorder or not preorder:
            return None

        root_val = preorder[0]
        root = Node(root_val)

        idx = inorder.index(root_val)
        lsize = idx
        rsize = len(inorder) - idx - 1

        root.left = self.buildtree(inorder[:idx], preorder[1:1 + lsize],n)
        root.right = self.buildtree(inorder[idx + 1:], preorder[1 + lsize:],n)

        return root

#{ 
 # Driver Code Starts
#Initial Template for Python 3

class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None

def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        inorder = [ int(x) for x in input().split() ]
        preorder = [ int(x) for x in input().split() ]
        
        root = Solution().buildtree(inorder, preorder, n)
        printPostorder(root)
        print()

# } Driver Code Ends