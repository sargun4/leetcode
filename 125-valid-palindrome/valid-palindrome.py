# class Solution:
#     def isPalindrome(self, s: str) -> bool:
#         l = 0
#         r = len(s) - 1
        
#         while l < r:
            
#             while l < r and s[l].isalnum() == False: 
#                 l += 1
#             while r > l and s[r].isalnum() == False: 
#                 r -= 1
#             if l > r or s[l].lower() != s[r].lower():
#                 return False
#             else:
#                 l += 1
#                 r -= 1
#         return True

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = [char.lower() for char in s if char.isalnum()]
        return s == s[::-1]