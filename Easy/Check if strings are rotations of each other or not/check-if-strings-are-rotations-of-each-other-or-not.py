class Solution:
    def areRotations(self,s1, s2):
        # Check if lengths are equal and not empty
        if len(s1) != len(s2) or len(s1) == 0:
            return False
    
        # Concatenate s1 with itself to check for rotation
        s1_concat = s1 + s1
    
        # Check if s2 is a substring of the concatenated s1
        return s2 in s1_concat

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s1=str(input())
        s2=str(input())
        if(Solution().areRotations(s1,s2)):
            print(1)
        else:
            print(0)
    
        
# } Driver Code Ends