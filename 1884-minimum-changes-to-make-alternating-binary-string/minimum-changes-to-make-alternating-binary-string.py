# class Solution:
#     def minOperations(self, s):
#         res = sum(i % 2 == int(c) for i, c in enumerate(s))
#         return min(res, len(s) - res)
class Solution:
    def minOperations(self, s: str) -> int:
        count1=0
        count2=0
        for i in range(len(s)):
            if i%2==0:
                if s[i]=='1':
                    count1 += 1
                if s[i]=='0':
                    count2 += 1
                
            else:
                if s[i]=='0':
                    count1 += 1
                if s[i]=='1':
                    count2 += 1

        return min(count1,count2)

                          




        