def buildTree(In, post, n):
    # n = len(In)
    instart, inend = 0, n - 1
    poststart, postend = 0, n - 1
    def solve(In, post, instart, inend, poststart, postend):
        if instart > inend:
            return None
        root = Node(post[postend])
        # find the index of root in In
        idx = instart
        while idx <= inend:
            if In[idx] == root.data:
                break
            idx += 1
        lsize=idx-instart
        rsize=inend-idx
        root.right=solve(In,post,idx+1,inend,postend-rsize,postend-1)
        root.left=solve(In,post,instart,idx-1,poststart,poststart+lsize-1)
        return root
    return solve(In, post, instart, inend, poststart, postend)



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
from collections import  defaultdict

#Contributed by : PranchalK


_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())



# Helper function that allocates  
# a new node  
class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

# This funtcion is here just to test  
def preOrder(node):
    if node == None:
        return
    print(node.data, end=" ")
    preOrder(node.left)
    preOrder(node.right)
    
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())  # number of nodes in tree
        in_order = list(map(int, input().strip().split()))  # parent child info in list
        post_order = list(map(int, input().strip().split()))  # parent child info in list
        preOrder(buildTree(in_order,post_order,n))
        print()


# } Driver Code Ends