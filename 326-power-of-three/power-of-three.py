class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n==1:
            return True
        if n<=0 or n%3!=0:
            return False
        return Solution.isPowerOfThree(self,n//3)
# import math
# class Solution:
#     def isPowerOfThree(self, n: int) -> bool:
#         if n <= 0:
#             return False
#         log = math.log10(n) / math.log10(3)
        # return int(log) == log

# def isPowerOfThree(self, n: int) -> bool:
#         if(n>1): 
#             while(n%3==0):
#                 n//=3
#         return n==1
# def isPowerOfThree(self, n: int) -> bool:
#     return  False if n<=0  else self.isPowerOfThree(n//3) if(n%3==0) else n==1 