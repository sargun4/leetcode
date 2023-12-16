# class Solution:
#     def longestCommonSubsequence(self, s1: str, s2: str) -> int:
#         dp=[[0 for j in range(len(s2)+1)] for i in range(len(s1)+1)]

#         for i in range(len(s1)-1,-1,-1):
#             for j in range(len(s2)-1,-1,-1):
#                 if(s1[i]==s2[j]):
#                     dp[i][j]=1+dp[i+1][j+1]
#                 else:
#                     dp[i][j]=max(dp[i+1][j],dp[i][j+1])
#         return dp[0][0]

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for i in range(len(text2) + 1)] for j in range(len(text1) + 1)]
        
        text1 = " " + text1
        text2 = " " + text2
        
        for i in range(1, len(text1)):
            for j in range(1, len(text2)):
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            
        return dp[-1][-1]