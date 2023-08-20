# class Solution:
#     #O(n^2)-tle
#     def maxArea(self, height: List[int]) -> int:
#         n=len(height)
#         maxwater=0
#         for i in range(n):
#             for j in range(i+1,n):
#                 ht=min(height[i],height[j])
#                 width=j-i
#                 currwater=ht*width
#                 maxwater=max(maxwater,currwater)
#         return maxwater
class Solution:
    def maxArea(self, height):
        i, j = 0, len(height) - 1
        res = 0
        while i < j:
            water = (j - i) * min(height[i], height[j])
            res=max(water,res)
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return res
# class Solution:
#     #O(n)
#     def maxArea(self, height: List[int]) -> int:
#         leftptr=0
#         n=len(height)
#         rightptr=n-1
#         maxwater=0
#         while(leftptr<rightptr):
#             ht=min(height[leftptr],height[rightptr])
#             width=rightptr-leftptr
#             currwater=ht*width
#             maxwater=max(maxwater,currwater)

#             if(height[leftptr]<height[rightptr]):
#                 leftptr+=1
#             else:
#                 rightptr-=1
#         return maxwater